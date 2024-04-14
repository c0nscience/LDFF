// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFEnemyTemple.h"

#include "LDFFAttributeSet.h"


// Sets default values
ALDFFEnemyTemple::ALDFFEnemyTemple()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AttributeSet = CreateDefaultSubobject<ULDFFAttributeSet>(TEXT("AttributeSet"));
}

// Called when the game starts or when spawned
void ALDFFEnemyTemple::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALDFFEnemyTemple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALDFFEnemyTemple::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

