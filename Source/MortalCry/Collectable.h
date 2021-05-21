// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Interactive.h"
#include "Collectable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCollectable : public UInteractive
{
	GENERATED_BODY()
};

/**
 * 
 */
class MORTALCRY_API ICollectable : public IInteractive
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FVector2D GetSize() const;
	
};
