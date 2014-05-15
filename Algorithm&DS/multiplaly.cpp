int64_t multi(int32_t a，int32_t b)
{

int64_t mulReslut = 0;
int32_t tmp = a;


while(b) {
if (b & 1) {
  mulResult = mulResult + tmp;
}
	tmp = tmp << 1;
	b = b >> 1;
}

return mulResult;

}
