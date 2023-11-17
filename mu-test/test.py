from pylibdmtx.pylibdmtx import encode
import numpy as np
from PIL import Image

data="BE8UA284TM"
data_bytes = data.encode('utf-8')
matrix = encode(data_bytes, size = '8x32', scheme = "C40")

print(matrix.width, matrix.height)

# 获取生成的DataMatrix码图像

img_array = np.frombuffer(matrix.pixels, dtype=np.uint8).reshape(60,180,3)
print(img_array.shape)
# img = Image.frombytes('RGB', (matrix.width, matrix.height), matrix.pixels)
# img_array = np.asarray(img)
img_stride = img_array[::5, ::5, ::3]
img_crop = img_stride[2:10, 2:34].reshape(8*32)
print(img_crop)
img_cvt = img_crop/255
print(img_cvt)
