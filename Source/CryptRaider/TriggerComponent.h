// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mover02.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRAIDER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public: 
	UTriggerComponent();

public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover02* Mover);
	
protected:
	virtual void BeginPlay() override;

private: 
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag = "Unlock1";

	UMover02* Mover;
	
	AActor* GetAcceptableActor() const;
};
