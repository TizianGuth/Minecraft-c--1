#pragma once

#include "Model.h"
#include "Blockytpe.h"
#include "Faces.h"
#include "PerlinNoise.h"
#include "vector.h"

const int CHUNK_SIZE = 16;
const int CHUNK_HEIGHT = 256;

class Chunk {
public:
	Chunk();
	~Chunk();

	void Generate();
	void GenerateMeshes();
	void FillUpTest();
	void SetChunkPosition(glm::vec2 chunkPosition);
public:
	Mesh m_Mesh;
	Model m_Model;
	glm::vec2 m_ChunkPosition;

private:
	std::vector<int> ConvertPositionToVertices(glm::vec3 position, int materialID);
	std::vector<int> ConvertPositionToIndex(int blockCount, Faces faces);
	Faces GetNeighbouringBlocks(glm::vec3 position);
	const int GetBlockFromOtherChunk(glm::vec3 position);
	const int GetIndex(glm::vec3 position);
	const int GetBlock(glm::vec3 position);

private:
	unsigned char m_blocks[CHUNK_SIZE * CHUNK_SIZE * CHUNK_HEIGHT];
	Vector3::UnsignedChar m_localBlockPositions[CHUNK_SIZE * CHUNK_SIZE * CHUNK_HEIGHT];
};