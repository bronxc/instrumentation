/*
 * File: DescriptorManager.h
 * Author: Agustin Gianni (agustingianni@gmail.com)
 *
 * Created on March 20, 2011, 4:36 PM
 */

#ifndef DESCRIPTORMANAGER_H
#define DESCRIPTORMANAGER_H

#include <string>
#include <memory>
#include <unordered_map>

#if defined(TARGET_WINDOWS)
typedef void *DescriptorType;
#else
typedef int DescriptorType;
#endif

struct DescriptorState {
	DescriptorState(DescriptorType descriptor) :
		descriptor(descriptor), r_off(0), w_off(0), origin("<undefined>"), closed(false) {
	}

	DescriptorType descriptor;

	// Reads from the descriptor will increase the read offset
	off_t r_off;

	// Writes to the descriptor will increase the write offset
	off_t w_off;

	// This could be a file, ip address, etc.
	std::string origin;

	bool closed;
};

class DescriptorManager {
public:
	typedef std::unordered_map<DescriptorType, std::shared_ptr<DescriptorState> > DescriptorMap;

	std::shared_ptr<DescriptorState> getDescriptorState(DescriptorType descriptor);
	std::shared_ptr<DescriptorState> createDescriptorState(DescriptorType descriptor);

	bool checkDescriptor(DescriptorType descriptor);
	void setDescriptorState(DescriptorType descriptor, std::shared_ptr<DescriptorState> ds);
	void dupDescriptorState(DescriptorType descriptor, std::shared_ptr<DescriptorState> ds);
	void removeDescriporState(DescriptorType descriptor);

private:
	DescriptorMap desc_map;
};

#endif // DESCRIPTORMANAGER_H
