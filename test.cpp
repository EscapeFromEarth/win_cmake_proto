#include"iostream"
#include"fstream"
#include"test.pb.h"

void prt(const test::Test &oTest){
	std::cout<<oTest.id()<<" ";
	for(const uint32_t x:oTest.vec()){
		std::cout<<x<<",";
	}
	std::cout<<" "<<oTest.str()<<"\n";
}

int main(){
	test::Test oTest,oTest2;
	oTest.set_id(123);
	oTest.add_vec(1);
	oTest.add_vec(2);
	oTest.add_vec(3);
	oTest.set_str("321");
	prt(oTest);
	std::ofstream ofs("./test.out");
	assert(ofs&&oTest.SerializeToOstream(&ofs));
	ofs.close();
	// 注意！！！C++打开二进制文件要特别用“std::ios::binary”指定，否则可能会读取不完整的。。。大草
	std::ifstream ifs("./test.out",std::ios::in|std::ios::binary);
	assert(ifs&&oTest2.ParseFromIstream(&ifs)); // 这种情况只会输出 123 1,2,3,
	ifs.close();
	prt(oTest2);
}
/*
123 1,2,3, 321
123 1,2,3, 321
*/