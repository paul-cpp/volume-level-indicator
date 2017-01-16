#pragma once

#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

int GetVolume()
{
	HRESULT hr = NULL;
	bool decibels = false;
	bool scalar = false;
	//double newVolume = nVolume;

	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
		CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;

	endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);

	endpointVolume->Release();

	CoUninitialize();

	return static_cast<int>  (currentVolume * 100);
}