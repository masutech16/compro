#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

# To fully customize the contents of this image, use the following Dockerfile as a base and add the RUN statement from this file:
# https://github.com/microsoft/vscode-dev-containers/blob/v0.112.0/containers/debian-10-git/.devcontainer/Dockerfile
FROM mcr.microsoft.com/vscode/devcontainers/base:0-debian-10

# This Dockerfile's base image has a non-root user with sudo access. Use the "remoteUser"
# property in devcontainer.json to use it. On Linux, the container user's GID/UIDs
# will be updated to match your local UID/GID (when using the dockerFile property).
# See https://aka.ms/vscode-remote/containers/non-root-user for details.
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    #
    # Install C++ tools
    && apt-get -y install build-essential cmake cppcheck valgrind \
    #
    # install oj, oj-verify, oj-template-generator
    && apt-get -y install python3-pip \
    && pip3 install online-judge-tools \
    && pip3 install online-judge-verify-helper \
    && pip3 install online-judge-template-generator \


    # [Optional] Update UID/GID if needed
    && if [ "$USER_GID" != "1000" ] || [ "$USER_UID" != "1000" ]; then \
        groupmod --gid $USER_GID $USERNAME \
        && usermod --uid $USER_UID --gid $USER_GID $USERNAME \
        && chown -R $USER_UID:$USER_GID /home/$USERNAME; \
    fi \
    #
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/* \
    #
    # set alias
    && echo "alias oj-submit='oj -c /workspaces/compro/oj/oj-cookie.jar s -y --no-open'" >> /home/vscode/.bashrc \
    && echo "alias g++='g++-8 -O2 -std=c++17 -I /workspaces/compro/lib -Wall -Wextra -DLOCAL -fuse-ld=gold -fsanitize=undefined'" >> /home/vscode/.bashrc \
    && echo "alias oj-bundle='oj-bundle -I /workspaces/compro/lib'" >> /home/vscode/.bashrc \
    && echo "alias oj-prepare='oj-prepare --config-file \"/workspaces/compro/oj/oj-prepare.config.toml\"'" >> /home/vscode/.bashrc


# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog
