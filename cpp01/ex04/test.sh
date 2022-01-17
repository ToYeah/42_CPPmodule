make;
mkdir testcase;
cd testcase;

cp ../replace .;

echo hellohellohellogood > hello.txt;
echo aaaaaaaaaaaaaaaaaaa > aaa.txt;
echo poppopoppopoppopoppo > poppo.txt;
echo permission > permission_output.txt;

echo permission > permission.txt;
echo permission > permission_output.txt.replace;

chmod 000 permission.txt
chmod 000 permission_output.txt.replace

./replace permission.txt nothing n;

./replace permission_output.txt permission p;

./replace nothing.txt nothing nothing;

./replace nothing.txt nothing nothing;

./replace hello.txt hello Hello;
cat hello.txt.replace;

./replace aaa.txt a b;
cat aaa.txt.replace;

./replace aaa.txt a a;
cat aaa.txt.replace;


./replace poppo.txt pop bob;
cat poppo.txt.replace;

cd ..;
rm -rf testcase;