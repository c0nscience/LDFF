// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Character.h"
#include "LDFFAIBaseCharacter.generated.h"

class ULDFFAttributeSet;
class UGameplayAbility;
class UAttributeSet;

UCLASS()
class LDFF_API ALDFFAIBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALDFFAIBaseCharacter();
	
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
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;
	
public:
	virtual void PossessedBy(AController* NewController) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
