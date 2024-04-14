// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFPlayerTemple.h"

#include "LDFFAttributeSet.h"
#include "LDFFPlayerState.h"


// Sets default values
ALDFFPlayerTemple::ALDFFPlayerTemple()
{
	PrimaryActorTick.bCanEverTick = true;
	AttributeSet = CreateDefaultSubobject<ULDFFAttributeSet>(TEXT("AttributeSet"));
}

// Called when the game starts or when spawned
void ALDFFPlayerTemple::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALDFFPlayerTemple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALDFFPlayerTemple::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

