// Fill out your copyright notice in the Description page of Project Settings.


#include "PushableObject.h"

APushableObject::APushableObject()
{
	PrimaryActorTick.bCanEverTick = false;

	UStaticMeshComponent* Mesh = GetStaticMeshComponent();
	Mesh->SetSimulatePhysics(true);
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetGenerateOverlapEvents(true);
}
