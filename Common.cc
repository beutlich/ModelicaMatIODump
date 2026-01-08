#include "ModelicaUtilities.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* ModelicaAllocateString(size_t len) {
    void *data = malloc(len + 1); /* Never free'd in the test programs */
    if (NULL == data) {
        ModelicaError("Failed to allocate string");
    }
    return (char*)data;
}

char* ModelicaAllocateStringWithErrorReturn(size_t len) {
    return (char*)malloc(len + 1); /* Never free'd in the test programs */
}

char* ModelicaDuplicateString(const char* str) {
    void *data = malloc(strlen(str) + 1); /* Never free'd in the test programs */
    if (NULL == data) {
        ModelicaError("Failed to duplicate string");
    }
    strcpy((char*)data, str);
    return (char*)data;
}

char* ModelicaDuplicateStringWithErrorReturn(const char* str) {
    void *data = malloc(strlen(str) + 1); /* Never free'd in the test programs */
    if (NULL != data) {
        strcpy((char*)data, str);
    }
    return (char*)data;
}

void ModelicaMessage(const char *string) {
    printf("%s", string);
}

void ModelicaWarning(const char *string) {
    printf("%s", string);
}

void ModelicaError(const char *string) {
	exit(EXIT_FAILURE);
}

void ModelicaFormatMessage(const char *string, ...) {
    va_list args;
    va_start(args, string);
    ModelicaVFormatMessage(string, args);
    va_end(args);
}

void ModelicaFormatWarning(const char *string, ...) {
    va_list args;
    va_start(args, string);
    ModelicaVFormatWarning(string, args);
    va_end(args);
}

void ModelicaFormatError(const char *string, ...) {
    va_list args;
    va_start(args, string);
    ModelicaVFormatError(string, args);
    va_end(args);
}

void ModelicaVFormatMessage(const char *string, va_list args) {
    vprintf(string, args);
}

void ModelicaVFormatWarning(const char *string, va_list args) {
    vprintf(string, args);
}

void ModelicaVFormatError(const char *string, va_list args) {
    vfprintf(stderr, string, args);
	exit(EXIT_FAILURE);
}
