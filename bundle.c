#include <assert.h>

#include "bundle.h"

bool
bundle_resource_path(char *path, size_t size, char const *name, char const *type)
{
    assert(path);
    assert(size > 0U);
    assert(name);
    CFBundleRef bundle = CFBundleGetMainBundle();
    if (bundle == NULL)
    {
        return false;
    }
    CFStringRef prefix = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingASCII);
    assert(prefix);
    CFStringRef postfix = CFStringCreateWithCString(kCFAllocatorDefault, type, kCFStringEncodingASCII);
    assert(postfix);
    CFURLRef URL = CFBundleCopyResourceURL(bundle, prefix, postfix, NULL);
    CFRelease(postfix);
    CFRelease(prefix);
    assert(URL);
    Boolean success = CFURLGetFileSystemRepresentation(URL, true, (UInt8 *)path, size);
    CFRelease(URL);
    return success;
}
