


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	//IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target);

	//if (ASCInterface)
	//{
	//	ASCInterface->GetAbilitySystemComponent();

	//}

	// UAbilitySystemBlueprintLibrary : GAS���� �����ϴ� ���� ���� �Լ��� ���Ե� ���̺귯��
	// ������ �ϴ� �Ͱ� ���� ����� �ϴ� �Լ�
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr)
		return;

	// Get Effect Spec
	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext(); // meke effect context()
	EffectContextHandle.AddSourceObject(this); // add source object
    const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);

	TargetASC->ApplyGameplayEffectSpecToSelf( *(EffectSpecHandle.Data.Get()) );
}

