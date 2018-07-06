#Need a CUDNN Library for Linux File (7 version for cuda 9.0)


#install cuda version 9.0
wget 'https://developer.nvidia.com/compute/cuda/9.0/Prod/local_installers/cuda-repo-ubuntu1604-9-0-local_9.0.176-1_amd64-deb'

sudo dpkg -i cuda-repo-ubuntu1604-9-0-local_9.0.176-1_amd64-deb
sudo apt-key add /var/cuda-repo-9-0-local/7fa2af80.pub
sudo apt-get update
sudo apt-get install cuda

wget 'https://developer.nvidia.com/compute/cuda/9.0/Prod/patches/1/cuda-repo-ubuntu1604-9-0-local-cublas-performance-update_1.0-1_amd64-deb'
wget 'https://developer.nvidia.com/compute/cuda/9.0/Prod/patches/2/cuda-repo-ubuntu1604-9-0-local-cublas-performance-update-2_1.0-1_amd64-deb'
wget 'https://developer.nvidia.com/compute/cuda/9.0/Prod/patches/3/cuda-repo-ubuntu1604-9-0-local-cublas-performance-update-3_1.0-1_amd64-deb'

#patch 1 2018 01 25
sudo dpkg -i cuda-repo-ubuntu1604-9-0-local-cublas-performance-update_1.0-1_amd64-deb
sudo apt-get -y update
sudo apt-get -y upgrade cuda
#patch 2 2018 03 05
sudo dpkg -i cuda-repo-ubuntu1604-9-0-local-cublas-performance-update-2_1.0-1_amd64-deb
sudo apt-get -y update
sudo apt-get -y upgrade cuda
#patch 3 2018 06 07
sudo dpkg -i cuda-repo-ubuntu1604-9-0-local-cublas-performance-update-3_1.0-1_amd64-deb
sudo apt-get -y update
sudo apt-get -y upgrade cuda


#install CUDNN
sudo tar -xzvf cudnn-9.0-linux-x64-v7.1.tgz
sudo mv cuda/include/* /usr/local/cuda-9.0/include
sudo mv cuda/lib64/* /usr/local/cuda-9.0/lib64
sudo rm cudnn-9.0-linux-x64-v7.1.tgz
sudo rm -rf cuda
