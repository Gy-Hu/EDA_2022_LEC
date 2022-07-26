## This is an installation script (tested) for Ubuntu system to setup FlowTune+VTR8.0

#### Installation Demo on Ubuntu 20.x.x
[Installation bash script](install.sh)
#### This is an installation script (tested) for Ubuntu and CentOS 7 to setup FlowTune+VTR8.0

```bash
# NOTE: This is an installation script (tested) for Ubuntu system
# git clone https://github.com/Yu-Utah/FlowTune;

# NOTE: Let's first install the required packages
# 	You can skip these if you have the packages in your machine, or use different methods to install these packages (e.g., if you use RedHat/CentOS, you will need to use "yum")

# sudo apt-get install libreadline-dev g++ make flex bison libgtk-3-dev;
# wget https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.1.tar.gz; tar -xvf openmpi-4.0.1.tar.gz
# cd openmpi-4.0.1; ./configure; make -j12 all install;
# you can skip this OpenMP installation if you have OpenMP library
# you can check whether you have OpenMP or the version using "echo |cpp -fopenmp -dM |grep -i open"
# Ubuntu 20.x.x includes OpenMP automatically


if ! [ -x "$(command -v cmake3)" ] && ! [ -x "$(command -v cmake)" ];
then
    echo "cmake and cmake3 could not be found"
    exit
fi

# NOTE: Let's compile FlowTune with ABC
cd src/; mkdir build; cd build; cmake3 ..;
abc_dir_path="my \$abc_dir_path = \"$(pwd)\"" 
#make -j12; export PATH=$PATH:$(pwd)

# NOTE: A quick test see if FlowTune has been installed correctly
cd ../../FlowTune-AIG-Optimization/
./single_design.sh adder2 adder2.blif 1 1 0 1 1

# NOTE: Now let's setup FlowTune + VTR 8.0
cd ../; pwd
git clone https://github.com/verilog-to-routing/vtr-verilog-to-routing;
cd vtr-verilog-to-routing; #make -j12;
cd vtr_flow;
vtr_flow_pth="my \$vtr_flow_path = \"$(pwd)\""
cd scripts/perl_libs/XML-TreePP-0.41/lib;
vtr_flow_xml_lib_path="$(pwd)"
cd ../../../../;
# follow VTR installation instruction to install other packages if you cannot compile VTR
echo $vtr_flow_pth # check your vtr flow path
echo $abc_dir_path # check your flowtune-abc path

cd ../../FlowTune-VTR-Flow;ls ftune_vtr_flow.pl
echo "IMPORTANT !! - You need to change ftune_vtr_flow.pl from line 56 - 60 accordingly"
echo "1) change the use lib path using <$vtr_flow_xml_lib_path>"
echo "2) change the vtr_flow_path using <$vtr_flow_pth>"
echo "3) change abc_dir_path using <$abc_dir_path>"

# NOTE: Setup the ftune_vtr_flow.pl
# IMPORTANT !! - You need to change ftune_vtr_flow.pl from line 56 - 60 according to your VTR installation
# 1) change the use lib path using "$vtr_flow_xml_lib_path"
# 2) change the vtr_flow_path using "$vtr_flow_pth"
# 3) change abc_dir_path using "$abc_dir_path"

# To run FlowTune with VTR, just run "./ftune_vtr_flow.pl <circuit_file> <architecture_file>"
```


