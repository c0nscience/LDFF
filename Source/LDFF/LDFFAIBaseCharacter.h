// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "LDFFAIBaseCharacter.generated.h"

class UAttributeSet;

UCLASS()
class LDFF_API ALDFFAIBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALDFFAIBaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	TObjectPtr<UAttributeSet> GetAttributeSet() const { return AttributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
