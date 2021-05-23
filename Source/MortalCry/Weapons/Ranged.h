// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Weapon.h"
#include "Ranged.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class URanged : public UWeapon
{
	GENERATED_BODY()
};

/**
 * 
 */
class MORTALCRY_API IRanged : public IWeapon
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetAmmo() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetMagazinesSize() const;

};