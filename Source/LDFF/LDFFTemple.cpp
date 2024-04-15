// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFTemple.h"

#include "LDFFAbilitySystemComponent.h"
#include "LDFFAttributeSet.h"
#include "LDFFPlayerState.h"

// Sets default values
ALDFFTemple::ALDFFTemple()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<ULDFFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

UAbilitySystemComponent* ALDFFTemple::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALDFFTemple::OnHealthChangedInternal(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
	OnHealthChanged_Called.Broadcast(Data.OldValue, Data.NewValue);
}

void ALDFFTemple::OnFollowerChangedInternal(const FOnAttributeChangeData& Data)
{
	OnFollowerChanged(Data.OldValue, Data.NewValue);
	OnFollowerChanged_Called.Broadcast(Data.OldValue, Data.NewValue);
}

// Called when the game starts or when spawned
void ALDFFTemple::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
		.AddUObject(this, &ALDFFTemple::OnHealthChangedInternal);
		
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetFollowerAttribute())
		.AddUObject(this, &ALDFFTemple::OnFollowerChangedInternal);
	}
	
}

// Called every frame
void ALDFFTemple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALDFFTemple::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
