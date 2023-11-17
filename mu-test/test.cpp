#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "dmtx.h"


int main(void)
{
    DmtxEncode *enc = dmtxEncodeCreate();
    unsigned char   str[] = "BE8UA284TM";

    // 设置C40 编码
    dmtxEncodeSetProp(enc, DmtxPropScheme, DmtxSchemeC40);
    dmtxEncodeSetProp(enc, DmtxPropSizeRequest, DmtxSymbol8x32);
    dmtxEncodeSetProp(enc, DmtxPropRowPadBytes, 3);


    assert(enc != NULL);
    dmtxEncodeDataMatrix(enc, strlen((const char *)str), str);

    size_t width = dmtxImageGetProp(enc->image, DmtxPropWidth);
    size_t height = dmtxImageGetProp(enc->image, DmtxPropHeight);
    size_t bytesPerPixel = dmtxImageGetProp(enc->image, DmtxPropBytesPerPixel);

    unsigned char *pxl = (unsigned char *)malloc(width * height * bytesPerPixel);
    assert(pxl != NULL);
    memcpy(pxl, enc->image->pxl, width * height * bytesPerPixel);

    printf("%ld, %ld, %ld\n", width, height, bytesPerPixel);
    return 0;
}