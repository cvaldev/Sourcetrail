#ifndef UTILITY_CLANG_H
#define UTILITY_CLANG_H

#include <memory>
#include <string>
#include <vector>

#include "clang/AST/Type.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclTemplate.h"

class DataType;

namespace utility
{
	DataType qualTypeToDataType(clang::QualType qualType);

	std::vector<std::string> getDeclNameHierarchy(clang::Decl* declaration);
	std::vector<std::string> getContextNameHierarchy(clang::DeclContext* declaration);
	std::string getDeclName(clang::NamedDecl* declaration);
	std::vector<std::string> getTemplateSpecializationParentNameHierarchy(clang::ClassTemplateSpecializationDecl* declaration);
	DataType templateArgumentToDataType(const clang::TemplateArgument& argument);
}

#endif // UTILITY_CLANG_H
