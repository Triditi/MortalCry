// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBase.h"

AWeaponBase::AWeaponBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;

	AActor::SetReplicateMovement(true);
	
	//GetSkeletalMeshComponent()->SetIsReplicated(true);
	
	InteractText = "<Name>";
}

void AWeaponBase::Sheath_Implementation()
{
	Execute_StopAttacking(this);
	Execute_StopAction(this);
	Execute_StopAlterAttack(this);
	Execute_StopAlterAction(this);
}

void AWeaponBase::Interact_Implementation(AActor* InInstigator)
{
	SetOwner(InInstigator);
	GetSkeletalMeshComponent()->SetSimulatePhysics(false);
	GetSkeletalMeshComponent()->SetCollisionProfileName("NoCollision");
}

void AWeaponBase::StopInteracting_Implementation()
{
	SetOwner(nullptr);
	GetSkeletalMeshComponent()->SetSimulatePhysics(true);
	GetSkeletalMeshComponent()->SetCollisionProfileName("BlockAll");
}

FString AWeaponBase::GetDescription_Implementation() const
{
	return InteractText
	.Replace(TEXT("<Name>"), *Execute_GetName(this))
	.Replace(TEXT("\n"), *FString("\n"));
}
