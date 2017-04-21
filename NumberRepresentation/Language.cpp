#include "Language.h"
#include "LanguageEnglish.h"
#include "LanguageVietnamese.h"

Language::~Language() {}

Language* Language::getLanguage(LanguageType type) {
    if (type == LanguageType::Vietnamese)
        return new LanguageVietnamese();

    return new LanguageEnglish();
}