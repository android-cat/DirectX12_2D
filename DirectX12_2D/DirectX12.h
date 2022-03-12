#pragma once
#include<Windows.h>
#include<tchar.h>
#include<d3d12.h>
#include<dxgi1_6.h>
#include<DirectXMath.h>
#include<vector>
#include<d3dcompiler.h>
#ifdef _DEBUG
#include<iostream>
#endif
#define window_width 1280
#define window_height 720

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"d3dcompiler.lib")

class DirectX12{
	ID3DBlob* _vsBlob = nullptr;
	ID3DBlob* _psBlob = nullptr;
	ID3DBlob* errorBlob = nullptr;
	IDXGIFactory6* _dxgiFactory = nullptr;
	ID3D12Device* _dev = nullptr;
	ID3D12CommandAllocator* _cmdAllocator = nullptr;
	ID3D12GraphicsCommandList* _cmdList = nullptr;
	ID3D12CommandQueue* _cmdQueue = nullptr;
	IDXGISwapChain4* _swapchain = nullptr;
	D3D12_COMMAND_QUEUE_DESC cmdQueueDesc = {};
	D3D12_VIEWPORT viewport = {};
	D3D12_RECT scissorrect = {};
	ID3D12PipelineState* _pipelinestate = nullptr;
	ID3D12RootSignature* rootsignature = nullptr;
	D3D12_VERTEX_BUFFER_VIEW vbView = {};
	D3D12_INDEX_BUFFER_VIEW ibView = {};
	ID3D12DescriptorHeap* rtvHeaps = nullptr;
	std::vector<ID3D12Resource*> _backBuffers;
	D3D12_RESOURCE_DESC resdesc = {};
	D3D12_HEAP_PROPERTIES heapprop = {};
	ID3D12Fence* _fence = nullptr;
	UINT64 _fenceVal = 0;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC gpipeline = {};
	void EnableDebugLayer();
	std::string CreateDevice();
	std::string CreateCommandQueue();
	std::string CreateSwapchain(HWND hwnd);
	std::string CreateHeaps();
	std::string SetSwapchainBuffers();
	std::string SetResources(size_t size, ID3D12Resource **buff);
	std::string SetPipeline();
	void SetPosition();
	void CompileShader();
	void SetBarrier(unsigned int bbIdx,int type);
	void SetFence();
public:
	void Init(HWND hwnd);
	void Run();
};
