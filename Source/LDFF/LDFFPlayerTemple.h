// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LDFFTemple.h"
#include "LDFFPlayerTemple.generated.h"

UCLASS()
class LDFF_API ALDFFPlayerTemple : public ALDFFTemple
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALDFFPlayerTemple();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
