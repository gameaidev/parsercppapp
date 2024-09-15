#pragma once

#ifdef PARSERLIBRARY_EXPORTS
#define PARSER_API __declspec(dllexport)
#else
#define PARSER_API __declspec(dllimport)
#endif
