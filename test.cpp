#include "iostream"
#include "stdint.h"
#include "stdio.h"
using namespace std;

struct Node {
	// length of the compressed path (prefix)
	uint32_t prefixLength;
	// number of non-null children
	uint16_t count;
	// node type
	int8_t type;
	// compressed path (prefix)
	uint8_t prefix[8];

	Node(int8_t type) : prefixLength(0), count(0), type(type) {}
};

void loadKey(uintptr_t tid, uint8_t key[]) {
	// Store the key of the tuple into the key vector
	// Implementation is database specific
	reinterpret_cast<uint64_t*>(key)[0] = __builtin_bswap64(tid);
}

inline Node* makeLeaf(uintptr_t tid) {
	// Create a pseudo-leaf
	return reinterpret_cast<Node*>((tid << 1) | 1);
}

inline uintptr_t getLeafValue(Node* node) {
	// The the value stored in the pseudo-leaf
	return reinterpret_cast<uintptr_t>(node) >> 1;
}

inline bool isLeaf(Node* node) {
	// Is the node a leaf?
	return reinterpret_cast<uintptr_t>(node) & 1;
}

void te(uintptr_t * port) {
	*port = 2;
}

int main(int argc, char const *argv[])
{
	uintptr_t pt = 67;
	Node *node = NULL;
	if (node == NULL) {
		node = makeLeaf(pt);
	}
	uintptr_t port = 0;
	cout << port << endl;
	te(&port);
	cout << port << endl;

	if (isLeaf(node)) {
		//uint8_t Key[8];
		//loadKey(getLeafValue(node), Key);

		cout << getLeafValue(node) << endl;

	}

	cout << endl << "sizeof(uintptr_t)=" << sizeof(uintptr_t) << endl;
	uint8_t key[8];
	loadKey(pt, key);
	cout << "pt = " << pt << endl;
	for (int i = 0; i < 8; ++i)
	{
		printf("%d ", (int)key[i] );
	}
	return 0;
}

