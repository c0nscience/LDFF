// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Pawn.h"
#include "LDFFTemple.generated.h"

struct FOnAttributeChangeData;
class ULDFFAttributeSet;
class UAttributeSet;

UCLASS()
class LDFF_API ALDFFTemple : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALDFFTemple();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	TObjectPtr<ULDFFAttributeSet> GetAttributeSet() const { return AttributeSet; }
	
	void OnHealthChangedInternal(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category="Abilities|Attributes")
	void OnHealthChanged(float OldValue, float NewValue);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<ULDFFAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
