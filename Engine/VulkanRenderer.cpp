// VulkanRenderer.cpp
#include "pch.h"
#include "VulkanRenderer.h"
#include <iostream>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>

VkInstance instance;

void VulkanRenderer::Init() {
    std::cout << "[Vulkan] Init()\n";

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "NeoGenesis";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "NeoGenesisEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Get required GLFW extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        std::cerr << "[Vulkan] Failed to create instance!\n";
        exit(-1);
    }

    std::cout << "[Vulkan] Vulkan instance created.\n";
}

void VulkanRenderer::Draw() {
    std::cout << "[Vulkan] Draw\n";
}

void VulkanRenderer::Shutdown() {
    std::cout << "[Vulkan] Shutdown\n";
}
