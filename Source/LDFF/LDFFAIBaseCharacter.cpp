// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFAIBaseCharacter.h"

#include "LDFFAbilitySystemComponent.h"
#include "LDFFAttributeSet.h"

// Sets default values
ALDFFAIBaseCharacter::ALDFFAIBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AbilitySystemComponent = CreateDefaultSubobject<ULDFFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<ULDFFAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ALDFFAIBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ALDFFAIBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		                      .AddUObject(this, &ALDFFAIBaseCharacter::OnHealthChangedInternal);
	}
}

void ALDFFAIBaseCharacter::OnHealthChangedInternal(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ALDFFAIBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// UE_LOG(LogTemp, Error, TEXT("%s() possessed by"), *FString(__FUNCTION__));
	for (const TSubclassOf<UGameplayAbility> Ability : Abilities)
	{
		GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(Ability));
	}
}

// Called every frame
void ALDFFAIBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
