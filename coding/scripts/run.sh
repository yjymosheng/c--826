#!/usr/bin/env bash 



RUN_COMMAND=$1

# 创建使用 cmake 的build dir
mkdir -p build

cd build || exit 1 
{
cmake .. && make 
} > /dev/null

# 无参数时提示帮助
if [ "$#" -eq 0 ]; then
  echo "Usage: ./scripts/run.sh <target1> [target2] ..."
  echo "Available targets found in CMakeLists.txt"
  exit 0
fi

# 逐个运行所有目标
for target in "$@"; do
  if [ -x "$target" ]; then
    echo "Running: $target"
    "./$target"
    echo ""
  else
    echo "Error: target '$target' not found or not executable."
    exit 1
  fi
done