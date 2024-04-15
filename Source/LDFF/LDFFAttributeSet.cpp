// Fill out your copyright notice in the Description page of Project Settings.


#include "LDFFAttributeSet.h"

ULDFFAttributeSet::ULDFFAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);

	InitMana(10.f);
	InitMaxMana(50.f);

	InitFollower(1.f);
	InitMaxFollower(10.f);
}
