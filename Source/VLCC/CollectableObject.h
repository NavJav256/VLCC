// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "CollectableObject.generated.h"

UCLASS()
class VLCC_API ACollectableObject : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:

	ACollectableObject();

	void ShowPickupWidget(bool bShowWidget);

	void Interact() override;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	int32 IndexOfArray;

	UPROPERTY(VisibleAnywhere, Category = "Pickup Properties")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Pickup Properties")
	class USphereComponent* AreaSphere;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	class UWidgetComponent* PickupWidget;

public:

	FORCEINLINE int32 GetIndex() { return IndexOfArray; }
};
