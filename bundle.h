#pragma once

#include <stddef.h>

#include <Carbon/Carbon.h>

bool
bundle_resource_path(char *path, size_t size, char const *name, char const *type);
