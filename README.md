# CBase64
C Base64 library.<br/>
C89, C99 and >C99 compatible, CPP98 and >CPP98 compatible, Embedded C compatible.

Example of use

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../CBase64/CBase64.h"

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wold-style-cast"
#endif /* defined(__clang__) */

int main(void)
{
    size_t encoded_len;
    size_t decoded_len;
    char* encoded;
    unsigned char* decoded;

    const char* text = "Hello, World!";

    printf("Original: %s\n", text);

    encoded = BASE64_Encode((const unsigned char*)text, (size_t)strlen(text), &encoded_len);
    printf("Encoded : %s\n", encoded);

    decoded = BASE64_Decode(encoded, &decoded_len);
    printf("Decoded : %.*s\n", (int)decoded_len, decoded);

    free(encoded);
    free(decoded);

    return(0);
}
```

# History of changes ...
