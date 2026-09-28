{ SDL_gpu.inc -- 1-to-1 from SDL_gpu.h (SDL 3.4.14) }

type
  SDL_GPUDevice = record
  end;
  PSDL_GPUDevice = ^SDL_GPUDevice;
  PPSDL_GPUDevice = ^PSDL_GPUDevice;
  SDL_GPUBuffer = record
  end;
  PSDL_GPUBuffer = ^SDL_GPUBuffer;
  PPSDL_GPUBuffer = ^PSDL_GPUBuffer;
  SDL_GPUTransferBuffer = record
  end;
  PSDL_GPUTransferBuffer = ^SDL_GPUTransferBuffer;
  PPSDL_GPUTransferBuffer = ^PSDL_GPUTransferBuffer;
  SDL_GPUTexture = record
  end;
  PSDL_GPUTexture = ^SDL_GPUTexture;
  PPSDL_GPUTexture = ^PSDL_GPUTexture;
  SDL_GPUSampler = record
  end;
  PSDL_GPUSampler = ^SDL_GPUSampler;
  PPSDL_GPUSampler = ^PSDL_GPUSampler;
  SDL_GPUShader = record
  end;
  PSDL_GPUShader = ^SDL_GPUShader;
  PPSDL_GPUShader = ^PSDL_GPUShader;
  SDL_GPUComputePipeline = record
  end;
  PSDL_GPUComputePipeline = ^SDL_GPUComputePipeline;
  PPSDL_GPUComputePipeline = ^PSDL_GPUComputePipeline;
  SDL_GPUGraphicsPipeline = record
  end;
  PSDL_GPUGraphicsPipeline = ^SDL_GPUGraphicsPipeline;
  PPSDL_GPUGraphicsPipeline = ^PSDL_GPUGraphicsPipeline;
  SDL_GPUCommandBuffer = record
  end;
  PSDL_GPUCommandBuffer = ^SDL_GPUCommandBuffer;
  PPSDL_GPUCommandBuffer = ^PSDL_GPUCommandBuffer;
  SDL_GPURenderPass = record
  end;
  PSDL_GPURenderPass = ^SDL_GPURenderPass;
  PPSDL_GPURenderPass = ^PSDL_GPURenderPass;
  SDL_GPUComputePass = record
  end;
  PSDL_GPUComputePass = ^SDL_GPUComputePass;
  PPSDL_GPUComputePass = ^PSDL_GPUComputePass;
  SDL_GPUCopyPass = record
  end;
  PSDL_GPUCopyPass = ^SDL_GPUCopyPass;
  PPSDL_GPUCopyPass = ^PSDL_GPUCopyPass;
  SDL_GPUFence = record
  end;
  PSDL_GPUFence = ^SDL_GPUFence;
  PPSDL_GPUFence = ^PSDL_GPUFence;
  SDL_GPUPrimitiveType = (
    SDL_GPU_PRIMITIVETYPE_TRIANGLELIST,
    SDL_GPU_PRIMITIVETYPE_TRIANGLESTRIP,
    SDL_GPU_PRIMITIVETYPE_LINELIST,
    SDL_GPU_PRIMITIVETYPE_LINESTRIP,
    SDL_GPU_PRIMITIVETYPE_POINTLIST
  );
  PSDL_GPUPrimitiveType = ^SDL_GPUPrimitiveType;
  PPSDL_GPUPrimitiveType = ^PSDL_GPUPrimitiveType;
  SDL_GPULoadOp = (
    SDL_GPU_LOADOP_LOAD,
    SDL_GPU_LOADOP_CLEAR,
    SDL_GPU_LOADOP_DONT_CARE
  );
  PSDL_GPULoadOp = ^SDL_GPULoadOp;
  PPSDL_GPULoadOp = ^PSDL_GPULoadOp;
  SDL_GPUStoreOp = (
    SDL_GPU_STOREOP_STORE,
    SDL_GPU_STOREOP_DONT_CARE,
    SDL_GPU_STOREOP_RESOLVE,
    SDL_GPU_STOREOP_RESOLVE_AND_STORE
  );
  PSDL_GPUStoreOp = ^SDL_GPUStoreOp;
  PPSDL_GPUStoreOp = ^PSDL_GPUStoreOp;
  SDL_GPUIndexElementSize = (
    SDL_GPU_INDEXELEMENTSIZE_16BIT,
    SDL_GPU_INDEXELEMENTSIZE_32BIT
  );
  PSDL_GPUIndexElementSize = ^SDL_GPUIndexElementSize;
  PPSDL_GPUIndexElementSize = ^PSDL_GPUIndexElementSize;
  SDL_GPUTextureFormat = (
    SDL_GPU_TEXTUREFORMAT_INVALID,
    SDL_GPU_TEXTUREFORMAT_A8_UNORM,
    SDL_GPU_TEXTUREFORMAT_R8_UNORM,
    SDL_GPU_TEXTUREFORMAT_R8G8_UNORM,
    SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM,
    SDL_GPU_TEXTUREFORMAT_R16_UNORM,
    SDL_GPU_TEXTUREFORMAT_R16G16_UNORM,
    SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UNORM,
    SDL_GPU_TEXTUREFORMAT_R10G10B10A2_UNORM,
    SDL_GPU_TEXTUREFORMAT_B5G6R5_UNORM,
    SDL_GPU_TEXTUREFORMAT_B5G5R5A1_UNORM,
    SDL_GPU_TEXTUREFORMAT_B4G4R4A4_UNORM,
    SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC4_R_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC5_RG_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM,
    SDL_GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT,
    SDL_GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT,
    SDL_GPU_TEXTUREFORMAT_R8_SNORM,
    SDL_GPU_TEXTUREFORMAT_R8G8_SNORM,
    SDL_GPU_TEXTUREFORMAT_R8G8B8A8_SNORM,
    SDL_GPU_TEXTUREFORMAT_R16_SNORM,
    SDL_GPU_TEXTUREFORMAT_R16G16_SNORM,
    SDL_GPU_TEXTUREFORMAT_R16G16B16A16_SNORM,
    SDL_GPU_TEXTUREFORMAT_R16_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R16G16_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R32_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R32G32_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT,
    SDL_GPU_TEXTUREFORMAT_R11G11B10_UFLOAT,
    SDL_GPU_TEXTUREFORMAT_R8_UINT,
    SDL_GPU_TEXTUREFORMAT_R8G8_UINT,
    SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UINT,
    SDL_GPU_TEXTUREFORMAT_R16_UINT,
    SDL_GPU_TEXTUREFORMAT_R16G16_UINT,
    SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UINT,
    SDL_GPU_TEXTUREFORMAT_R32_UINT,
    SDL_GPU_TEXTUREFORMAT_R32G32_UINT,
    SDL_GPU_TEXTUREFORMAT_R32G32B32A32_UINT,
    SDL_GPU_TEXTUREFORMAT_R8_INT,
    SDL_GPU_TEXTUREFORMAT_R8G8_INT,
    SDL_GPU_TEXTUREFORMAT_R8G8B8A8_INT,
    SDL_GPU_TEXTUREFORMAT_R16_INT,
    SDL_GPU_TEXTUREFORMAT_R16G16_INT,
    SDL_GPU_TEXTUREFORMAT_R16G16B16A16_INT,
    SDL_GPU_TEXTUREFORMAT_R32_INT,
    SDL_GPU_TEXTUREFORMAT_R32G32_INT,
    SDL_GPU_TEXTUREFORMAT_R32G32B32A32_INT,
    SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_D16_UNORM,
    SDL_GPU_TEXTUREFORMAT_D24_UNORM,
    SDL_GPU_TEXTUREFORMAT_D32_FLOAT,
    SDL_GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT,
    SDL_GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT,
    SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM,
    SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB,
    SDL_GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT,
    SDL_GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT
  );
  PSDL_GPUTextureFormat = ^SDL_GPUTextureFormat;
  PPSDL_GPUTextureFormat = ^PSDL_GPUTextureFormat;
  SDL_GPUTextureUsageFlags = Uint32;
  PSDL_GPUTextureUsageFlags = ^SDL_GPUTextureUsageFlags;
  PPSDL_GPUTextureUsageFlags = ^PSDL_GPUTextureUsageFlags;
  SDL_GPUTextureType = (
    SDL_GPU_TEXTURETYPE_2D,
    SDL_GPU_TEXTURETYPE_2D_ARRAY,
    SDL_GPU_TEXTURETYPE_3D,
    SDL_GPU_TEXTURETYPE_CUBE,
    SDL_GPU_TEXTURETYPE_CUBE_ARRAY
  );
  PSDL_GPUTextureType = ^SDL_GPUTextureType;
  PPSDL_GPUTextureType = ^PSDL_GPUTextureType;
  SDL_GPUSampleCount = (
    SDL_GPU_SAMPLECOUNT_1,
    SDL_GPU_SAMPLECOUNT_2,
    SDL_GPU_SAMPLECOUNT_4,
    SDL_GPU_SAMPLECOUNT_8
  );
  PSDL_GPUSampleCount = ^SDL_GPUSampleCount;
  PPSDL_GPUSampleCount = ^PSDL_GPUSampleCount;
  SDL_GPUCubeMapFace = (
    SDL_GPU_CUBEMAPFACE_POSITIVEX,
    SDL_GPU_CUBEMAPFACE_NEGATIVEX,
    SDL_GPU_CUBEMAPFACE_POSITIVEY,
    SDL_GPU_CUBEMAPFACE_NEGATIVEY,
    SDL_GPU_CUBEMAPFACE_POSITIVEZ,
    SDL_GPU_CUBEMAPFACE_NEGATIVEZ
  );
  PSDL_GPUCubeMapFace = ^SDL_GPUCubeMapFace;
  PPSDL_GPUCubeMapFace = ^PSDL_GPUCubeMapFace;
  SDL_GPUBufferUsageFlags = Uint32;
  PSDL_GPUBufferUsageFlags = ^SDL_GPUBufferUsageFlags;
  PPSDL_GPUBufferUsageFlags = ^PSDL_GPUBufferUsageFlags;
  SDL_GPUTransferBufferUsage = (
    SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD,
    SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD
  );
  PSDL_GPUTransferBufferUsage = ^SDL_GPUTransferBufferUsage;
  PPSDL_GPUTransferBufferUsage = ^PSDL_GPUTransferBufferUsage;
  SDL_GPUShaderStage = (
    SDL_GPU_SHADERSTAGE_VERTEX,
    SDL_GPU_SHADERSTAGE_FRAGMENT
  );
  PSDL_GPUShaderStage = ^SDL_GPUShaderStage;
  PPSDL_GPUShaderStage = ^PSDL_GPUShaderStage;
  SDL_GPUShaderFormat = Uint32;
  PSDL_GPUShaderFormat = ^SDL_GPUShaderFormat;
  PPSDL_GPUShaderFormat = ^PSDL_GPUShaderFormat;
  SDL_GPUVertexElementFormat = (
    SDL_GPU_VERTEXELEMENTFORMAT_INVALID,
    SDL_GPU_VERTEXELEMENTFORMAT_INT,
    SDL_GPU_VERTEXELEMENTFORMAT_INT2,
    SDL_GPU_VERTEXELEMENTFORMAT_INT3,
    SDL_GPU_VERTEXELEMENTFORMAT_INT4,
    SDL_GPU_VERTEXELEMENTFORMAT_UINT,
    SDL_GPU_VERTEXELEMENTFORMAT_UINT2,
    SDL_GPU_VERTEXELEMENTFORMAT_UINT3,
    SDL_GPU_VERTEXELEMENTFORMAT_UINT4,
    SDL_GPU_VERTEXELEMENTFORMAT_FLOAT,
    SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2,
    SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3,
    SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4,
    SDL_GPU_VERTEXELEMENTFORMAT_BYTE2,
    SDL_GPU_VERTEXELEMENTFORMAT_BYTE4,
    SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2,
    SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4,
    SDL_GPU_VERTEXELEMENTFORMAT_BYTE2_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_BYTE4_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_SHORT2,
    SDL_GPU_VERTEXELEMENTFORMAT_SHORT4,
    SDL_GPU_VERTEXELEMENTFORMAT_USHORT2,
    SDL_GPU_VERTEXELEMENTFORMAT_USHORT4,
    SDL_GPU_VERTEXELEMENTFORMAT_SHORT2_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_SHORT4_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_USHORT2_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_USHORT4_NORM,
    SDL_GPU_VERTEXELEMENTFORMAT_HALF2,
    SDL_GPU_VERTEXELEMENTFORMAT_HALF4
  );
  PSDL_GPUVertexElementFormat = ^SDL_GPUVertexElementFormat;
  PPSDL_GPUVertexElementFormat = ^PSDL_GPUVertexElementFormat;
  SDL_GPUVertexInputRate = (
    SDL_GPU_VERTEXINPUTRATE_VERTEX,
    SDL_GPU_VERTEXINPUTRATE_INSTANCE
  );
  PSDL_GPUVertexInputRate = ^SDL_GPUVertexInputRate;
  PPSDL_GPUVertexInputRate = ^PSDL_GPUVertexInputRate;
  SDL_GPUFillMode = (
    SDL_GPU_FILLMODE_FILL,
    SDL_GPU_FILLMODE_LINE
  );
  PSDL_GPUFillMode = ^SDL_GPUFillMode;
  PPSDL_GPUFillMode = ^PSDL_GPUFillMode;
  SDL_GPUCullMode = (
    SDL_GPU_CULLMODE_NONE,
    SDL_GPU_CULLMODE_FRONT,
    SDL_GPU_CULLMODE_BACK
  );
  PSDL_GPUCullMode = ^SDL_GPUCullMode;
  PPSDL_GPUCullMode = ^PSDL_GPUCullMode;
  SDL_GPUFrontFace = (
    SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE,
    SDL_GPU_FRONTFACE_CLOCKWISE
  );
  PSDL_GPUFrontFace = ^SDL_GPUFrontFace;
  PPSDL_GPUFrontFace = ^PSDL_GPUFrontFace;
  SDL_GPUCompareOp = (
    SDL_GPU_COMPAREOP_INVALID,
    SDL_GPU_COMPAREOP_NEVER,
    SDL_GPU_COMPAREOP_LESS,
    SDL_GPU_COMPAREOP_EQUAL,
    SDL_GPU_COMPAREOP_LESS_OR_EQUAL,
    SDL_GPU_COMPAREOP_GREATER,
    SDL_GPU_COMPAREOP_NOT_EQUAL,
    SDL_GPU_COMPAREOP_GREATER_OR_EQUAL,
    SDL_GPU_COMPAREOP_ALWAYS
  );
  PSDL_GPUCompareOp = ^SDL_GPUCompareOp;
  PPSDL_GPUCompareOp = ^PSDL_GPUCompareOp;
  SDL_GPUStencilOp = (
    SDL_GPU_STENCILOP_INVALID,
    SDL_GPU_STENCILOP_KEEP,
    SDL_GPU_STENCILOP_ZERO,
    SDL_GPU_STENCILOP_REPLACE,
    SDL_GPU_STENCILOP_INCREMENT_AND_CLAMP,
    SDL_GPU_STENCILOP_DECREMENT_AND_CLAMP,
    SDL_GPU_STENCILOP_INVERT,
    SDL_GPU_STENCILOP_INCREMENT_AND_WRAP,
    SDL_GPU_STENCILOP_DECREMENT_AND_WRAP
  );
  PSDL_GPUStencilOp = ^SDL_GPUStencilOp;
  PPSDL_GPUStencilOp = ^PSDL_GPUStencilOp;
  SDL_GPUBlendOp = (
    SDL_GPU_BLENDOP_INVALID,
    SDL_GPU_BLENDOP_ADD,
    SDL_GPU_BLENDOP_SUBTRACT,
    SDL_GPU_BLENDOP_REVERSE_SUBTRACT,
    SDL_GPU_BLENDOP_MIN,
    SDL_GPU_BLENDOP_MAX
  );
  PSDL_GPUBlendOp = ^SDL_GPUBlendOp;
  PPSDL_GPUBlendOp = ^PSDL_GPUBlendOp;
  SDL_GPUBlendFactor = (
    SDL_GPU_BLENDFACTOR_INVALID,
    SDL_GPU_BLENDFACTOR_ZERO,
    SDL_GPU_BLENDFACTOR_ONE,
    SDL_GPU_BLENDFACTOR_SRC_COLOR,
    SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR,
    SDL_GPU_BLENDFACTOR_DST_COLOR,
    SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR,
    SDL_GPU_BLENDFACTOR_SRC_ALPHA,
    SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
    SDL_GPU_BLENDFACTOR_DST_ALPHA,
    SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA,
    SDL_GPU_BLENDFACTOR_CONSTANT_COLOR,
    SDL_GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR,
    SDL_GPU_BLENDFACTOR_SRC_ALPHA_SATURATE
  );
  PSDL_GPUBlendFactor = ^SDL_GPUBlendFactor;
  PPSDL_GPUBlendFactor = ^PSDL_GPUBlendFactor;
  SDL_GPUColorComponentFlags = Uint8;
  PSDL_GPUColorComponentFlags = ^SDL_GPUColorComponentFlags;
  PPSDL_GPUColorComponentFlags = ^PSDL_GPUColorComponentFlags;
  SDL_GPUFilter = (
    SDL_GPU_FILTER_NEAREST,
    SDL_GPU_FILTER_LINEAR
  );
  PSDL_GPUFilter = ^SDL_GPUFilter;
  PPSDL_GPUFilter = ^PSDL_GPUFilter;
  SDL_GPUSamplerMipmapMode = (
    SDL_GPU_SAMPLERMIPMAPMODE_NEAREST,
    SDL_GPU_SAMPLERMIPMAPMODE_LINEAR
  );
  PSDL_GPUSamplerMipmapMode = ^SDL_GPUSamplerMipmapMode;
  PPSDL_GPUSamplerMipmapMode = ^PSDL_GPUSamplerMipmapMode;
  SDL_GPUSamplerAddressMode = (
    SDL_GPU_SAMPLERADDRESSMODE_REPEAT,
    SDL_GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT,
    SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE
  );
  PSDL_GPUSamplerAddressMode = ^SDL_GPUSamplerAddressMode;
  PPSDL_GPUSamplerAddressMode = ^PSDL_GPUSamplerAddressMode;
  SDL_GPUPresentMode = (
    SDL_GPU_PRESENTMODE_VSYNC,
    SDL_GPU_PRESENTMODE_IMMEDIATE,
    SDL_GPU_PRESENTMODE_MAILBOX
  );
  PSDL_GPUPresentMode = ^SDL_GPUPresentMode;
  PPSDL_GPUPresentMode = ^PSDL_GPUPresentMode;
  SDL_GPUSwapchainComposition = (
    SDL_GPU_SWAPCHAINCOMPOSITION_SDR,
    SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR,
    SDL_GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR,
    SDL_GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084
  );
  PSDL_GPUSwapchainComposition = ^SDL_GPUSwapchainComposition;
  PPSDL_GPUSwapchainComposition = ^PSDL_GPUSwapchainComposition;
  PSDL_GPUViewport = ^SDL_GPUViewport;
  PPSDL_GPUViewport = ^PSDL_GPUViewport;
  SDL_GPUViewport = record
    x: Single;
    y: Single;
    w: Single;
    h: Single;
    min_depth: Single;
    max_depth: Single;
  end;
  PSDL_GPUTextureTransferInfo = ^SDL_GPUTextureTransferInfo;
  PPSDL_GPUTextureTransferInfo = ^PSDL_GPUTextureTransferInfo;
  SDL_GPUTextureTransferInfo = record
    transfer_buffer: PSDL_GPUTransferBuffer;
    offset: Uint32;
    pixels_per_row: Uint32;
    rows_per_layer: Uint32;
  end;
  PSDL_GPUTransferBufferLocation = ^SDL_GPUTransferBufferLocation;
  PPSDL_GPUTransferBufferLocation = ^PSDL_GPUTransferBufferLocation;
  SDL_GPUTransferBufferLocation = record
    transfer_buffer: PSDL_GPUTransferBuffer;
    offset: Uint32;
  end;
  PSDL_GPUTextureLocation = ^SDL_GPUTextureLocation;
  PPSDL_GPUTextureLocation = ^PSDL_GPUTextureLocation;
  SDL_GPUTextureLocation = record
    texture: PSDL_GPUTexture;
    mip_level: Uint32;
    layer: Uint32;
    x: Uint32;
    y: Uint32;
    z: Uint32;
  end;
  PSDL_GPUTextureRegion = ^SDL_GPUTextureRegion;
  PPSDL_GPUTextureRegion = ^PSDL_GPUTextureRegion;
  SDL_GPUTextureRegion = record
    texture: PSDL_GPUTexture;
    mip_level: Uint32;
    layer: Uint32;
    x: Uint32;
    y: Uint32;
    z: Uint32;
    w: Uint32;
    h: Uint32;
    d: Uint32;
  end;
  PSDL_GPUBlitRegion = ^SDL_GPUBlitRegion;
  PPSDL_GPUBlitRegion = ^PSDL_GPUBlitRegion;
  SDL_GPUBlitRegion = record
    texture: PSDL_GPUTexture;
    mip_level: Uint32;
    layer_or_depth_plane: Uint32;
    x: Uint32;
    y: Uint32;
    w: Uint32;
    h: Uint32;
  end;
  PSDL_GPUBufferLocation = ^SDL_GPUBufferLocation;
  PPSDL_GPUBufferLocation = ^PSDL_GPUBufferLocation;
  SDL_GPUBufferLocation = record
    buffer: PSDL_GPUBuffer;
    offset: Uint32;
  end;
  PSDL_GPUBufferRegion = ^SDL_GPUBufferRegion;
  PPSDL_GPUBufferRegion = ^PSDL_GPUBufferRegion;
  SDL_GPUBufferRegion = record
    buffer: PSDL_GPUBuffer;
    offset: Uint32;
    size: Uint32;
  end;
  PSDL_GPUIndirectDrawCommand = ^SDL_GPUIndirectDrawCommand;
  PPSDL_GPUIndirectDrawCommand = ^PSDL_GPUIndirectDrawCommand;
  SDL_GPUIndirectDrawCommand = record
    num_vertices: Uint32;
    num_instances: Uint32;
    first_vertex: Uint32;
    first_instance: Uint32;
  end;
  PSDL_GPUIndexedIndirectDrawCommand = ^SDL_GPUIndexedIndirectDrawCommand;
  PPSDL_GPUIndexedIndirectDrawCommand = ^PSDL_GPUIndexedIndirectDrawCommand;
  SDL_GPUIndexedIndirectDrawCommand = record
    num_indices: Uint32;
    num_instances: Uint32;
    first_index: Uint32;
    vertex_offset: Sint32;
    first_instance: Uint32;
  end;
  PSDL_GPUIndirectDispatchCommand = ^SDL_GPUIndirectDispatchCommand;
  PPSDL_GPUIndirectDispatchCommand = ^PSDL_GPUIndirectDispatchCommand;
  SDL_GPUIndirectDispatchCommand = record
    groupcount_x: Uint32;
    groupcount_y: Uint32;
    groupcount_z: Uint32;
  end;
  PSDL_GPUSamplerCreateInfo = ^SDL_GPUSamplerCreateInfo;
  PPSDL_GPUSamplerCreateInfo = ^PSDL_GPUSamplerCreateInfo;
  SDL_GPUSamplerCreateInfo = record
    min_filter: SDL_GPUFilter;
    mag_filter: SDL_GPUFilter;
    mipmap_mode: SDL_GPUSamplerMipmapMode;
    address_mode_u: SDL_GPUSamplerAddressMode;
    address_mode_v: SDL_GPUSamplerAddressMode;
    address_mode_w: SDL_GPUSamplerAddressMode;
    mip_lod_bias: Single;
    max_anisotropy: Single;
    compare_op: SDL_GPUCompareOp;
    min_lod: Single;
    max_lod: Single;
    enable_anisotropy: Boolean;
    enable_compare: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUVertexBufferDescription = ^SDL_GPUVertexBufferDescription;
  PPSDL_GPUVertexBufferDescription = ^PSDL_GPUVertexBufferDescription;
  SDL_GPUVertexBufferDescription = record
    slot: Uint32;
    pitch: Uint32;
    input_rate: SDL_GPUVertexInputRate;
    instance_step_rate: Uint32;
  end;
  PSDL_GPUVertexAttribute = ^SDL_GPUVertexAttribute;
  PPSDL_GPUVertexAttribute = ^PSDL_GPUVertexAttribute;
  SDL_GPUVertexAttribute = record
    location: Uint32;
    buffer_slot: Uint32;
    format: SDL_GPUVertexElementFormat;
    offset: Uint32;
  end;
  PSDL_GPUVertexInputState = ^SDL_GPUVertexInputState;
  PPSDL_GPUVertexInputState = ^PSDL_GPUVertexInputState;
  SDL_GPUVertexInputState = record
    vertex_buffer_descriptions: PSDL_GPUVertexBufferDescription;
    num_vertex_buffers: Uint32;
    vertex_attributes: PSDL_GPUVertexAttribute;
    num_vertex_attributes: Uint32;
  end;
  PSDL_GPUStencilOpState = ^SDL_GPUStencilOpState;
  PPSDL_GPUStencilOpState = ^PSDL_GPUStencilOpState;
  SDL_GPUStencilOpState = record
    fail_op: SDL_GPUStencilOp;
    pass_op: SDL_GPUStencilOp;
    depth_fail_op: SDL_GPUStencilOp;
    compare_op: SDL_GPUCompareOp;
  end;
  PSDL_GPUColorTargetBlendState = ^SDL_GPUColorTargetBlendState;
  PPSDL_GPUColorTargetBlendState = ^PSDL_GPUColorTargetBlendState;
  SDL_GPUColorTargetBlendState = record
    src_color_blendfactor: SDL_GPUBlendFactor;
    dst_color_blendfactor: SDL_GPUBlendFactor;
    color_blend_op: SDL_GPUBlendOp;
    src_alpha_blendfactor: SDL_GPUBlendFactor;
    dst_alpha_blendfactor: SDL_GPUBlendFactor;
    alpha_blend_op: SDL_GPUBlendOp;
    color_write_mask: SDL_GPUColorComponentFlags;
    enable_blend: Boolean;
    enable_color_write_mask: Boolean;
    padding1: Uint8;
    padding2: Uint8;
  end;
  PSDL_GPUShaderCreateInfo = ^SDL_GPUShaderCreateInfo;
  PPSDL_GPUShaderCreateInfo = ^PSDL_GPUShaderCreateInfo;
  SDL_GPUShaderCreateInfo = record
    code_size: NativeUInt;
    code: PUint8;
    entrypoint: PUTF8Char;
    format: SDL_GPUShaderFormat;
    stage: SDL_GPUShaderStage;
    num_samplers: Uint32;
    num_storage_textures: Uint32;
    num_storage_buffers: Uint32;
    num_uniform_buffers: Uint32;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUTextureCreateInfo = ^SDL_GPUTextureCreateInfo;
  PPSDL_GPUTextureCreateInfo = ^PSDL_GPUTextureCreateInfo;
  SDL_GPUTextureCreateInfo = record
    type_: SDL_GPUTextureType;
    format: SDL_GPUTextureFormat;
    usage: SDL_GPUTextureUsageFlags;
    width: Uint32;
    height: Uint32;
    layer_count_or_depth: Uint32;
    num_levels: Uint32;
    sample_count: SDL_GPUSampleCount;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUBufferCreateInfo = ^SDL_GPUBufferCreateInfo;
  PPSDL_GPUBufferCreateInfo = ^PSDL_GPUBufferCreateInfo;
  SDL_GPUBufferCreateInfo = record
    usage: SDL_GPUBufferUsageFlags;
    size: Uint32;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUTransferBufferCreateInfo = ^SDL_GPUTransferBufferCreateInfo;
  PPSDL_GPUTransferBufferCreateInfo = ^PSDL_GPUTransferBufferCreateInfo;
  SDL_GPUTransferBufferCreateInfo = record
    usage: SDL_GPUTransferBufferUsage;
    size: Uint32;
    props: SDL_PropertiesID;
  end;
  PSDL_GPURasterizerState = ^SDL_GPURasterizerState;
  PPSDL_GPURasterizerState = ^PSDL_GPURasterizerState;
  SDL_GPURasterizerState = record
    fill_mode: SDL_GPUFillMode;
    cull_mode: SDL_GPUCullMode;
    front_face: SDL_GPUFrontFace;
    depth_bias_constant_factor: Single;
    depth_bias_clamp: Single;
    depth_bias_slope_factor: Single;
    enable_depth_bias: Boolean;
    enable_depth_clip: Boolean;
    padding1: Uint8;
    padding2: Uint8;
  end;
  PSDL_GPUMultisampleState = ^SDL_GPUMultisampleState;
  PPSDL_GPUMultisampleState = ^PSDL_GPUMultisampleState;
  SDL_GPUMultisampleState = record
    sample_count: SDL_GPUSampleCount;
    sample_mask: Uint32;
    enable_mask: Boolean;
    enable_alpha_to_coverage: Boolean;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUDepthStencilState = ^SDL_GPUDepthStencilState;
  PPSDL_GPUDepthStencilState = ^PSDL_GPUDepthStencilState;
  SDL_GPUDepthStencilState = record
    compare_op: SDL_GPUCompareOp;
    back_stencil_state: SDL_GPUStencilOpState;
    front_stencil_state: SDL_GPUStencilOpState;
    compare_mask: Uint8;
    write_mask: Uint8;
    enable_depth_test: Boolean;
    enable_depth_write: Boolean;
    enable_stencil_test: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUColorTargetDescription = ^SDL_GPUColorTargetDescription;
  PPSDL_GPUColorTargetDescription = ^PSDL_GPUColorTargetDescription;
  SDL_GPUColorTargetDescription = record
    format: SDL_GPUTextureFormat;
    blend_state: SDL_GPUColorTargetBlendState;
  end;
  PSDL_GPUGraphicsPipelineTargetInfo = ^SDL_GPUGraphicsPipelineTargetInfo;
  PPSDL_GPUGraphicsPipelineTargetInfo = ^PSDL_GPUGraphicsPipelineTargetInfo;
  SDL_GPUGraphicsPipelineTargetInfo = record
    color_target_descriptions: PSDL_GPUColorTargetDescription;
    num_color_targets: Uint32;
    depth_stencil_format: SDL_GPUTextureFormat;
    has_depth_stencil_target: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUGraphicsPipelineCreateInfo = ^SDL_GPUGraphicsPipelineCreateInfo;
  PPSDL_GPUGraphicsPipelineCreateInfo = ^PSDL_GPUGraphicsPipelineCreateInfo;
  SDL_GPUGraphicsPipelineCreateInfo = record
    vertex_shader: PSDL_GPUShader;
    fragment_shader: PSDL_GPUShader;
    vertex_input_state: SDL_GPUVertexInputState;
    primitive_type: SDL_GPUPrimitiveType;
    rasterizer_state: SDL_GPURasterizerState;
    multisample_state: SDL_GPUMultisampleState;
    depth_stencil_state: SDL_GPUDepthStencilState;
    target_info: SDL_GPUGraphicsPipelineTargetInfo;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUComputePipelineCreateInfo = ^SDL_GPUComputePipelineCreateInfo;
  PPSDL_GPUComputePipelineCreateInfo = ^PSDL_GPUComputePipelineCreateInfo;
  SDL_GPUComputePipelineCreateInfo = record
    code_size: NativeUInt;
    code: PUint8;
    entrypoint: PUTF8Char;
    format: SDL_GPUShaderFormat;
    num_samplers: Uint32;
    num_readonly_storage_textures: Uint32;
    num_readonly_storage_buffers: Uint32;
    num_readwrite_storage_textures: Uint32;
    num_readwrite_storage_buffers: Uint32;
    num_uniform_buffers: Uint32;
    threadcount_x: Uint32;
    threadcount_y: Uint32;
    threadcount_z: Uint32;
    props: SDL_PropertiesID;
  end;
  PSDL_GPUColorTargetInfo = ^SDL_GPUColorTargetInfo;
  PPSDL_GPUColorTargetInfo = ^PSDL_GPUColorTargetInfo;
  SDL_GPUColorTargetInfo = record
    texture: PSDL_GPUTexture;
    mip_level: Uint32;
    layer_or_depth_plane: Uint32;
    clear_color: SDL_FColor;
    load_op: SDL_GPULoadOp;
    store_op: SDL_GPUStoreOp;
    resolve_texture: PSDL_GPUTexture;
    resolve_mip_level: Uint32;
    resolve_layer: Uint32;
    cycle: Boolean;
    cycle_resolve_texture: Boolean;
    padding1: Uint8;
    padding2: Uint8;
  end;
  PSDL_GPUDepthStencilTargetInfo = ^SDL_GPUDepthStencilTargetInfo;
  PPSDL_GPUDepthStencilTargetInfo = ^PSDL_GPUDepthStencilTargetInfo;
  SDL_GPUDepthStencilTargetInfo = record
    texture: PSDL_GPUTexture;
    clear_depth: Single;
    load_op: SDL_GPULoadOp;
    store_op: SDL_GPUStoreOp;
    stencil_load_op: SDL_GPULoadOp;
    stencil_store_op: SDL_GPUStoreOp;
    cycle: Boolean;
    clear_stencil: Uint8;
    mip_level: Uint8;
    layer: Uint8;
  end;
  PSDL_GPUBlitInfo = ^SDL_GPUBlitInfo;
  PPSDL_GPUBlitInfo = ^PSDL_GPUBlitInfo;
  SDL_GPUBlitInfo = record
    source: SDL_GPUBlitRegion;
    destination: SDL_GPUBlitRegion;
    load_op: SDL_GPULoadOp;
    clear_color: SDL_FColor;
    flip_mode: SDL_FlipMode;
    filter: SDL_GPUFilter;
    cycle: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUBufferBinding = ^SDL_GPUBufferBinding;
  PPSDL_GPUBufferBinding = ^PSDL_GPUBufferBinding;
  SDL_GPUBufferBinding = record
    buffer: PSDL_GPUBuffer;
    offset: Uint32;
  end;
  PSDL_GPUTextureSamplerBinding = ^SDL_GPUTextureSamplerBinding;
  PPSDL_GPUTextureSamplerBinding = ^PSDL_GPUTextureSamplerBinding;
  SDL_GPUTextureSamplerBinding = record
    texture: PSDL_GPUTexture;
    sampler: PSDL_GPUSampler;
  end;
  PSDL_GPUStorageBufferReadWriteBinding = ^SDL_GPUStorageBufferReadWriteBinding;
  PPSDL_GPUStorageBufferReadWriteBinding = ^PSDL_GPUStorageBufferReadWriteBinding;
  SDL_GPUStorageBufferReadWriteBinding = record
    buffer: PSDL_GPUBuffer;
    cycle: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUStorageTextureReadWriteBinding = ^SDL_GPUStorageTextureReadWriteBinding;
  PPSDL_GPUStorageTextureReadWriteBinding = ^PSDL_GPUStorageTextureReadWriteBinding;
  SDL_GPUStorageTextureReadWriteBinding = record
    texture: PSDL_GPUTexture;
    mip_level: Uint32;
    layer: Uint32;
    cycle: Boolean;
    padding1: Uint8;
    padding2: Uint8;
    padding3: Uint8;
  end;
  PSDL_GPUVulkanOptions = ^SDL_GPUVulkanOptions;
  PPSDL_GPUVulkanOptions = ^PSDL_GPUVulkanOptions;
  SDL_GPUVulkanOptions = record
    vulkan_api_version: Uint32;
    feature_list: Pointer;
    vulkan_10_physical_device_features: Pointer;
    device_extension_count: Uint32;
    device_extension_names: PPUTF8Char;
    instance_extension_count: Uint32;
    instance_extension_names: PPUTF8Char;
  end;

const
  SDL_GPU_TEXTUREUSAGE_SAMPLER = 1 shl 0;
  SDL_GPU_TEXTUREUSAGE_COLOR_TARGET = 1 shl 1;
  SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET = 1 shl 2;
  SDL_GPU_TEXTUREUSAGE_GRAPHICS_STORAGE_READ = 1 shl 3;
  SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_READ = 1 shl 4;
  SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_WRITE = 1 shl 5;
  SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_SIMULTANEOUS_READ_WRITE = 1 shl 6;
  SDL_GPU_BUFFERUSAGE_VERTEX = 1 shl 0;
  SDL_GPU_BUFFERUSAGE_INDEX = 1 shl 1;
  SDL_GPU_BUFFERUSAGE_INDIRECT = 1 shl 2;
  SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ = 1 shl 3;
  SDL_GPU_BUFFERUSAGE_COMPUTE_STORAGE_READ = 1 shl 4;
  SDL_GPU_BUFFERUSAGE_COMPUTE_STORAGE_WRITE = 1 shl 5;
  SDL_GPU_SHADERFORMAT_INVALID = 0;
  SDL_GPU_SHADERFORMAT_PRIVATE = 1 shl 0;
  SDL_GPU_SHADERFORMAT_SPIRV = 1 shl 1;
  SDL_GPU_SHADERFORMAT_DXBC = 1 shl 2;
  SDL_GPU_SHADERFORMAT_DXIL = 1 shl 3;
  SDL_GPU_SHADERFORMAT_MSL = 1 shl 4;
  SDL_GPU_SHADERFORMAT_METALLIB = 1 shl 5;
  SDL_GPU_COLORCOMPONENT_R = 1 shl 0;
  SDL_GPU_COLORCOMPONENT_G = 1 shl 1;
  SDL_GPU_COLORCOMPONENT_B = 1 shl 2;
  SDL_GPU_COLORCOMPONENT_A = 1 shl 3;
  SDL_PROP_GPU_DEVICE_CREATE_DEBUGMODE_BOOLEAN = 'SDL.gpu.device.create.debugmode';
  SDL_PROP_GPU_DEVICE_CREATE_PREFERLOWPOWER_BOOLEAN = 'SDL.gpu.device.create.preferlowpower';
  SDL_PROP_GPU_DEVICE_CREATE_VERBOSE_BOOLEAN = 'SDL.gpu.device.create.verbose';
  SDL_PROP_GPU_DEVICE_CREATE_NAME_STRING = 'SDL.gpu.device.create.name';
  SDL_PROP_GPU_DEVICE_CREATE_FEATURE_CLIP_DISTANCE_BOOLEAN = 'SDL.gpu.device.create.feature.clip_distance';
  SDL_PROP_GPU_DEVICE_CREATE_FEATURE_DEPTH_CLAMPING_BOOLEAN = 'SDL.gpu.device.create.feature.depth_clamping';
  SDL_PROP_GPU_DEVICE_CREATE_FEATURE_INDIRECT_DRAW_FIRST_INSTANCE_BOOLEAN = 'SDL.gpu.device.create.feature.indirect_draw_first_instance';
  SDL_PROP_GPU_DEVICE_CREATE_FEATURE_ANISOTROPY_BOOLEAN = 'SDL.gpu.device.create.feature.anisotropy';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_PRIVATE_BOOLEAN = 'SDL.gpu.device.create.shaders.private';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_SPIRV_BOOLEAN = 'SDL.gpu.device.create.shaders.spirv';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_DXBC_BOOLEAN = 'SDL.gpu.device.create.shaders.dxbc';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_DXIL_BOOLEAN = 'SDL.gpu.device.create.shaders.dxil';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_MSL_BOOLEAN = 'SDL.gpu.device.create.shaders.msl';
  SDL_PROP_GPU_DEVICE_CREATE_SHADERS_METALLIB_BOOLEAN = 'SDL.gpu.device.create.shaders.metallib';
  SDL_PROP_GPU_DEVICE_CREATE_D3D12_ALLOW_FEWER_RESOURCE_SLOTS_BOOLEAN = 'SDL.gpu.device.create.d3d12.allowtier1resourcebinding';
  SDL_PROP_GPU_DEVICE_CREATE_D3D12_SEMANTIC_NAME_STRING = 'SDL.gpu.device.create.d3d12.semantic';
  SDL_PROP_GPU_DEVICE_CREATE_D3D12_AGILITY_SDK_VERSION_NUMBER = 'SDL.gpu.device.create.d3d12.agility_sdk_version';
  SDL_PROP_GPU_DEVICE_CREATE_D3D12_AGILITY_SDK_PATH_STRING = 'SDL.gpu.device.create.d3d12.agility_sdk_path';
  SDL_PROP_GPU_DEVICE_CREATE_VULKAN_REQUIRE_HARDWARE_ACCELERATION_BOOLEAN = 'SDL.gpu.device.create.vulkan.requirehardwareacceleration';
  SDL_PROP_GPU_DEVICE_CREATE_VULKAN_OPTIONS_POINTER = 'SDL.gpu.device.create.vulkan.options';
  SDL_PROP_GPU_DEVICE_CREATE_METAL_ALLOW_MACFAMILY1_BOOLEAN = 'SDL.gpu.device.create.metal.allowmacfamily1';
  SDL_PROP_GPU_DEVICE_NAME_STRING = 'SDL.gpu.device.name';
  SDL_PROP_GPU_DEVICE_DRIVER_NAME_STRING = 'SDL.gpu.device.driver_name';
  SDL_PROP_GPU_DEVICE_DRIVER_VERSION_STRING = 'SDL.gpu.device.driver_version';
  SDL_PROP_GPU_DEVICE_DRIVER_INFO_STRING = 'SDL.gpu.device.driver_info';
  SDL_PROP_GPU_COMPUTEPIPELINE_CREATE_NAME_STRING = 'SDL.gpu.computepipeline.create.name';
  SDL_PROP_GPU_GRAPHICSPIPELINE_CREATE_NAME_STRING = 'SDL.gpu.graphicspipeline.create.name';
  SDL_PROP_GPU_SAMPLER_CREATE_NAME_STRING = 'SDL.gpu.sampler.create.name';
  SDL_PROP_GPU_SHADER_CREATE_NAME_STRING = 'SDL.gpu.shader.create.name';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_R_FLOAT = 'SDL.gpu.texture.create.d3d12.clear.r';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_G_FLOAT = 'SDL.gpu.texture.create.d3d12.clear.g';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_B_FLOAT = 'SDL.gpu.texture.create.d3d12.clear.b';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_A_FLOAT = 'SDL.gpu.texture.create.d3d12.clear.a';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_DEPTH_FLOAT = 'SDL.gpu.texture.create.d3d12.clear.depth';
  SDL_PROP_GPU_TEXTURE_CREATE_D3D12_CLEAR_STENCIL_NUMBER = 'SDL.gpu.texture.create.d3d12.clear.stencil';
  SDL_PROP_GPU_TEXTURE_CREATE_NAME_STRING = 'SDL.gpu.texture.create.name';
  SDL_PROP_GPU_BUFFER_CREATE_NAME_STRING = 'SDL.gpu.buffer.create.name';
  SDL_PROP_GPU_TRANSFERBUFFER_CREATE_NAME_STRING = 'SDL.gpu.transferbuffer.create.name';

function SDL_GPUSupportsShaderFormats(format_flags: SDL_GPUShaderFormat; name: PUTF8Char): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GPUSupportsProperties(props: SDL_PropertiesID): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUDevice(format_flags: SDL_GPUShaderFormat; debug_mode: Boolean; name: PUTF8Char): PSDL_GPUDevice; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUDeviceWithProperties(props: SDL_PropertiesID): PSDL_GPUDevice; cdecl;
  external SDL_LIB_NAME;
procedure SDL_DestroyGPUDevice(device: PSDL_GPUDevice); cdecl;
  external SDL_LIB_NAME;
function SDL_GetNumGPUDrivers: Integer; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUDriver(index: Integer): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUDeviceDriver(device: PSDL_GPUDevice): PUTF8Char; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUShaderFormats(device: PSDL_GPUDevice): SDL_GPUShaderFormat; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUDeviceProperties(device: PSDL_GPUDevice): SDL_PropertiesID; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUComputePipeline(device: PSDL_GPUDevice; createinfo: PSDL_GPUComputePipelineCreateInfo): PSDL_GPUComputePipeline; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUGraphicsPipeline(device: PSDL_GPUDevice; createinfo: PSDL_GPUGraphicsPipelineCreateInfo): PSDL_GPUGraphicsPipeline; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUSampler(device: PSDL_GPUDevice; createinfo: PSDL_GPUSamplerCreateInfo): PSDL_GPUSampler; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUShader(device: PSDL_GPUDevice; createinfo: PSDL_GPUShaderCreateInfo): PSDL_GPUShader; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUTexture(device: PSDL_GPUDevice; createinfo: PSDL_GPUTextureCreateInfo): PSDL_GPUTexture; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUBuffer(device: PSDL_GPUDevice; createinfo: PSDL_GPUBufferCreateInfo): PSDL_GPUBuffer; cdecl;
  external SDL_LIB_NAME;
function SDL_CreateGPUTransferBuffer(device: PSDL_GPUDevice; createinfo: PSDL_GPUTransferBufferCreateInfo): PSDL_GPUTransferBuffer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUBufferName(device: PSDL_GPUDevice; buffer: PSDL_GPUBuffer; text: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUTextureName(device: PSDL_GPUDevice; texture: PSDL_GPUTexture; text: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
procedure SDL_InsertGPUDebugLabel(command_buffer: PSDL_GPUCommandBuffer; text: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
procedure SDL_PushGPUDebugGroup(command_buffer: PSDL_GPUCommandBuffer; name: PUTF8Char); cdecl;
  external SDL_LIB_NAME;
procedure SDL_PopGPUDebugGroup(command_buffer: PSDL_GPUCommandBuffer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUTexture(device: PSDL_GPUDevice; texture: PSDL_GPUTexture); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUSampler(device: PSDL_GPUDevice; sampler: PSDL_GPUSampler); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUBuffer(device: PSDL_GPUDevice; buffer: PSDL_GPUBuffer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUTransferBuffer(device: PSDL_GPUDevice; transfer_buffer: PSDL_GPUTransferBuffer); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUComputePipeline(device: PSDL_GPUDevice; compute_pipeline: PSDL_GPUComputePipeline); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUShader(device: PSDL_GPUDevice; shader: PSDL_GPUShader); cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUGraphicsPipeline(device: PSDL_GPUDevice; graphics_pipeline: PSDL_GPUGraphicsPipeline); cdecl;
  external SDL_LIB_NAME;
function SDL_AcquireGPUCommandBuffer(device: PSDL_GPUDevice): PSDL_GPUCommandBuffer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_PushGPUVertexUniformData(command_buffer: PSDL_GPUCommandBuffer; slot_index: Uint32; data: Pointer; length: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_PushGPUFragmentUniformData(command_buffer: PSDL_GPUCommandBuffer; slot_index: Uint32; data: Pointer; length: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_PushGPUComputeUniformData(command_buffer: PSDL_GPUCommandBuffer; slot_index: Uint32; data: Pointer; length: Uint32); cdecl;
  external SDL_LIB_NAME;
function SDL_BeginGPURenderPass(command_buffer: PSDL_GPUCommandBuffer; color_target_infos: PSDL_GPUColorTargetInfo; num_color_targets: Uint32; depth_stencil_target_info: PSDL_GPUDepthStencilTargetInfo): PSDL_GPURenderPass; cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUGraphicsPipeline(render_pass: PSDL_GPURenderPass; graphics_pipeline: PSDL_GPUGraphicsPipeline); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUViewport(render_pass: PSDL_GPURenderPass; viewport: PSDL_GPUViewport); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUScissor(render_pass: PSDL_GPURenderPass; scissor: PSDL_Rect); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUBlendConstants(render_pass: PSDL_GPURenderPass; blend_constants: SDL_FColor); cdecl;
  external SDL_LIB_NAME;
procedure SDL_SetGPUStencilReference(render_pass: PSDL_GPURenderPass; reference: Uint8); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUVertexBuffers(render_pass: PSDL_GPURenderPass; first_slot: Uint32; bindings: PSDL_GPUBufferBinding; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUIndexBuffer(render_pass: PSDL_GPURenderPass; binding: PSDL_GPUBufferBinding; index_element_size: SDL_GPUIndexElementSize); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUVertexSamplers(render_pass: PSDL_GPURenderPass; first_slot: Uint32; texture_sampler_bindings: PSDL_GPUTextureSamplerBinding; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUVertexStorageTextures(render_pass: PSDL_GPURenderPass; first_slot: Uint32; storage_textures: PPSDL_GPUTexture; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUVertexStorageBuffers(render_pass: PSDL_GPURenderPass; first_slot: Uint32; storage_buffers: PPSDL_GPUBuffer; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUFragmentSamplers(render_pass: PSDL_GPURenderPass; first_slot: Uint32; texture_sampler_bindings: PSDL_GPUTextureSamplerBinding; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUFragmentStorageTextures(render_pass: PSDL_GPURenderPass; first_slot: Uint32; storage_textures: PPSDL_GPUTexture; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUFragmentStorageBuffers(render_pass: PSDL_GPURenderPass; first_slot: Uint32; storage_buffers: PPSDL_GPUBuffer; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DrawGPUIndexedPrimitives(render_pass: PSDL_GPURenderPass; num_indices: Uint32; num_instances: Uint32; first_index: Uint32; vertex_offset: Sint32; first_instance: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DrawGPUPrimitives(render_pass: PSDL_GPURenderPass; num_vertices: Uint32; num_instances: Uint32; first_vertex: Uint32; first_instance: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DrawGPUPrimitivesIndirect(render_pass: PSDL_GPURenderPass; buffer: PSDL_GPUBuffer; offset: Uint32; draw_count: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DrawGPUIndexedPrimitivesIndirect(render_pass: PSDL_GPURenderPass; buffer: PSDL_GPUBuffer; offset: Uint32; draw_count: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_EndGPURenderPass(render_pass: PSDL_GPURenderPass); cdecl;
  external SDL_LIB_NAME;
function SDL_BeginGPUComputePass(command_buffer: PSDL_GPUCommandBuffer; storage_texture_bindings: PSDL_GPUStorageTextureReadWriteBinding; num_storage_texture_bindings: Uint32; storage_buffer_bindings: PSDL_GPUStorageBufferReadWriteBinding; num_storage_buffer_bindings: Uint32): PSDL_GPUComputePass; cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUComputePipeline(compute_pass: PSDL_GPUComputePass; compute_pipeline: PSDL_GPUComputePipeline); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUComputeSamplers(compute_pass: PSDL_GPUComputePass; first_slot: Uint32; texture_sampler_bindings: PSDL_GPUTextureSamplerBinding; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUComputeStorageTextures(compute_pass: PSDL_GPUComputePass; first_slot: Uint32; storage_textures: PPSDL_GPUTexture; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BindGPUComputeStorageBuffers(compute_pass: PSDL_GPUComputePass; first_slot: Uint32; storage_buffers: PPSDL_GPUBuffer; num_bindings: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DispatchGPUCompute(compute_pass: PSDL_GPUComputePass; groupcount_x: Uint32; groupcount_y: Uint32; groupcount_z: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DispatchGPUComputeIndirect(compute_pass: PSDL_GPUComputePass; buffer: PSDL_GPUBuffer; offset: Uint32); cdecl;
  external SDL_LIB_NAME;
procedure SDL_EndGPUComputePass(compute_pass: PSDL_GPUComputePass); cdecl;
  external SDL_LIB_NAME;
function SDL_MapGPUTransferBuffer(device: PSDL_GPUDevice; transfer_buffer: PSDL_GPUTransferBuffer; cycle: Boolean): Pointer; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UnmapGPUTransferBuffer(device: PSDL_GPUDevice; transfer_buffer: PSDL_GPUTransferBuffer); cdecl;
  external SDL_LIB_NAME;
function SDL_BeginGPUCopyPass(command_buffer: PSDL_GPUCommandBuffer): PSDL_GPUCopyPass; cdecl;
  external SDL_LIB_NAME;
procedure SDL_UploadToGPUTexture(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUTextureTransferInfo; destination: PSDL_GPUTextureRegion; cycle: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_UploadToGPUBuffer(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUTransferBufferLocation; destination: PSDL_GPUBufferRegion; cycle: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_CopyGPUTextureToTexture(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUTextureLocation; destination: PSDL_GPUTextureLocation; w: Uint32; h: Uint32; d: Uint32; cycle: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_CopyGPUBufferToBuffer(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUBufferLocation; destination: PSDL_GPUBufferLocation; size: Uint32; cycle: Boolean); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DownloadFromGPUTexture(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUTextureRegion; destination: PSDL_GPUTextureTransferInfo); cdecl;
  external SDL_LIB_NAME;
procedure SDL_DownloadFromGPUBuffer(copy_pass: PSDL_GPUCopyPass; source: PSDL_GPUBufferRegion; destination: PSDL_GPUTransferBufferLocation); cdecl;
  external SDL_LIB_NAME;
procedure SDL_EndGPUCopyPass(copy_pass: PSDL_GPUCopyPass); cdecl;
  external SDL_LIB_NAME;
procedure SDL_GenerateMipmapsForGPUTexture(command_buffer: PSDL_GPUCommandBuffer; texture: PSDL_GPUTexture); cdecl;
  external SDL_LIB_NAME;
procedure SDL_BlitGPUTexture(command_buffer: PSDL_GPUCommandBuffer; info: PSDL_GPUBlitInfo); cdecl;
  external SDL_LIB_NAME;
function SDL_WindowSupportsGPUSwapchainComposition(device: PSDL_GPUDevice; window: PSDL_Window; swapchain_composition: SDL_GPUSwapchainComposition): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WindowSupportsGPUPresentMode(device: PSDL_GPUDevice; window: PSDL_Window; present_mode: SDL_GPUPresentMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_ClaimWindowForGPUDevice(device: PSDL_GPUDevice; window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseWindowFromGPUDevice(device: PSDL_GPUDevice; window: PSDL_Window); cdecl;
  external SDL_LIB_NAME;
function SDL_SetGPUSwapchainParameters(device: PSDL_GPUDevice; window: PSDL_Window; swapchain_composition: SDL_GPUSwapchainComposition; present_mode: SDL_GPUPresentMode): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SetGPUAllowedFramesInFlight(device: PSDL_GPUDevice; allowed_frames_in_flight: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUSwapchainTextureFormat(device: PSDL_GPUDevice; window: PSDL_Window): SDL_GPUTextureFormat; cdecl;
  external SDL_LIB_NAME;
function SDL_AcquireGPUSwapchainTexture(command_buffer: PSDL_GPUCommandBuffer; window: PSDL_Window; swapchain_texture: PPSDL_GPUTexture; swapchain_texture_width: PUint32; swapchain_texture_height: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitForGPUSwapchain(device: PSDL_GPUDevice; window: PSDL_Window): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer: PSDL_GPUCommandBuffer; window: PSDL_Window; swapchain_texture: PPSDL_GPUTexture; swapchain_texture_width: PUint32; swapchain_texture_height: PUint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SubmitGPUCommandBuffer(command_buffer: PSDL_GPUCommandBuffer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_SubmitGPUCommandBufferAndAcquireFence(command_buffer: PSDL_GPUCommandBuffer): PSDL_GPUFence; cdecl;
  external SDL_LIB_NAME;
function SDL_CancelGPUCommandBuffer(command_buffer: PSDL_GPUCommandBuffer): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitForGPUIdle(device: PSDL_GPUDevice): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_WaitForGPUFences(device: PSDL_GPUDevice; wait_all: Boolean; fences: PPSDL_GPUFence; num_fences: Uint32): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_QueryGPUFence(device: PSDL_GPUDevice; fence: PSDL_GPUFence): Boolean; cdecl;
  external SDL_LIB_NAME;
procedure SDL_ReleaseGPUFence(device: PSDL_GPUDevice; fence: PSDL_GPUFence); cdecl;
  external SDL_LIB_NAME;
function SDL_GPUTextureFormatTexelBlockSize(format: SDL_GPUTextureFormat): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_GPUTextureSupportsFormat(device: PSDL_GPUDevice; format: SDL_GPUTextureFormat; type_: SDL_GPUTextureType; usage: SDL_GPUTextureUsageFlags): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_GPUTextureSupportsSampleCount(device: PSDL_GPUDevice; format: SDL_GPUTextureFormat; sample_count: SDL_GPUSampleCount): Boolean; cdecl;
  external SDL_LIB_NAME;
function SDL_CalculateGPUTextureFormatSize(format: SDL_GPUTextureFormat; width: Uint32; height: Uint32; depth_or_layer_count: Uint32): Uint32; cdecl;
  external SDL_LIB_NAME;
function SDL_GetPixelFormatFromGPUTextureFormat(format: SDL_GPUTextureFormat): SDL_PixelFormat; cdecl;
  external SDL_LIB_NAME;
function SDL_GetGPUTextureFormatFromPixelFormat(format: SDL_PixelFormat): SDL_GPUTextureFormat; cdecl;
  external SDL_LIB_NAME;
procedure SDL_GDKSuspendGPU(device: PSDL_GPUDevice); cdecl;
  external SDL_LIB_NAME;
procedure SDL_GDKResumeGPU(device: PSDL_GPUDevice); cdecl;
  external SDL_LIB_NAME;
