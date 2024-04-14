// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFTemple.h"

#include "LDFFAbilitySystemComponent.h"
#include "LDFFAttributeSet.h"

// Sets default values
ALDFFTemple::ALDFFTemple()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<ULDFFAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<ULDFFAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ALDFFTemple::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ALDFFTemple::BeginPlay()
{
	Super::BeginPlay();
	
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
