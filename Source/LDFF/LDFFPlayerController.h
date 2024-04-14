// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "LDFFPlayerController.generated.h"

class UGameplayAbility;
class ULDFFGameplayAbility;
class UAttributeSet;
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS()
class ALDFFPlayerController : public APlayerController, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ALDFFPlayerController();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;
	
	virtual void BeginPlay() override;
	
};


