// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFAIBaseCharacter.h"

#include "LDFFAbilitySystemComponent.h"
#include "LDFFAttributeSet.h"

// Sets default values
ALDFFAIBaseCharacter::ALDFFAIBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
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
	
}

// Called every frame
void ALDFFAIBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
