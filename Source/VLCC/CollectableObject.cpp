// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableObject.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "VLCCCharacter.h"

ACollectableObject::ACollectableObject()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(RootComponent);

	AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(RootComponent);
}

void ACollectableObject::BeginPlay()
{
	Super::BeginPlay();
	
	if (PickupWidget)
	{
		PickupWidget->SetVisibility(false);
	}

	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectableObject::OnSphereOverlap);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &ACollectableObject::OnSphereEndOverlap);
}

void ACollectableObject::Interact()
{
	Destroy();
}

void ACollectableObject::ShowPickupWidget(bool bShowWidget)
{
	if (PickupWidget)
	{
		PickupWidget->SetVisibility(bShowWidget);
	}
}

void ACollectableObject::OnSphereOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVLCCCharacter* VLCCCharacter = Cast<AVLCCCharacter>(OtherActor);
	if (VLCCCharacter)
	{
		VLCCCharacter->SetCollectedItem(this);
	}
}

void ACollectableObject::OnSphereEndOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AVLCCCharacter* VLCCCharacter = Cast<AVLCCCharacter>(OtherActor);
	if (VLCCCharacter)
	{
		VLCCCharacter->SetCollectedItem(nullptr);
	}
}


