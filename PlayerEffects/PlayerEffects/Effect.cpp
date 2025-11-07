#include "Effect.h"

std::unique_ptr<Effect> Effect::makeEffect(EffectType type) {
    {
        switch (type) {
            case EffectType::Slow: return std::make_unique<Slow>();
            case EffectType::Burn: return std::make_unique<Burn>();
            default: return nullptr;
        }
}
}
