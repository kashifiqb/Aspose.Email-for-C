# Aspose.Email for C++ zip distribution must be used to build qt applications
# nuget packages not yet supported
# set ASPOSE_ROOT and ASPOSE_EMAIL_CPP_ROOT environment variables to 
# directory where content of Aspose.Email_for_C++_XX.X.zip is extracted
# :SET ASPOSE_ROOT=C:\project\Release\CodePorting.Native.Cs2Cpp_internal_20.8
export ASPOSE_ROOT="/mnt/c/project/Release/CodePorting.Native.Cs2Cpp_internal_20.8"
export ASPOSE_EMAIL_CPP_ROOT="/mnt/c/project/net.master/tmp/Aspose.Email.Cpp"
export CC="gcc"
export CXX="g++"

rm -rf "build"
mkdir "build"
cd "build"
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]
then
  cmake --build . --config Release -- -j5
fi
