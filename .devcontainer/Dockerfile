# Use an appropriate base image with necessary dependencies for building
FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND noninteractive
ENV LANG C.UTF-8

# Update package lists and install necessary packages
RUN sudo apt-get update && \
sudo apt-get install -y \
dpkg-dev \
cmake \
g++ \
gcc \
binutils \
libx11-dev \
libxpm-dev \
libxft-dev \
libxext-dev \
libpng-dev \
libjpeg-dev \
python3 \
libssl-dev \
wget \
&& sudo apt-get clean \
&& sudo rm -rf /var/lib/apt/lists/*


# Install ROOT
RUN wget https://root.cern/download/root_v6.30.06.Linux-almalinux9.3-x86_64-gcc11.4.tar.gz &&\
tar -xzvf root_v6.30.06.Linux-almalinux9.3-x86_64-gcc11.4.tar.gz &&\
source root/bin/thisroot.sh # also available: thisroot.{csh,fish,bat}

# Set environment variables for ROOT
ENV ROOTSYS /usr/local/root
ENV PATH $ROOTSYS/bin:$PATH
ENV LD_LIBRARY_PATH $ROOTSYS/lib:$LD_LIBRARY_PATH
ENV PYTHONPATH $ROOTSYS/lib:$PYTHONPATH

# Install Fastjet
RUN git clone https://github.com/FAST-Project/fastjet.git && \
    cd fastjet && \
    ./configure && \
    make && \
    make check && \
    make install && \
    cd .. && \
    rm -rf fastjet

# Create the working directory
RUN mkdir /app

# Set working directory
WORKDIR /app

# Copy your application files to the container
COPY . .

# Install Python dependencies
RUN pip3 install -r requirements.txt

# Specify the command to run on container start
CMD ["bash"]
