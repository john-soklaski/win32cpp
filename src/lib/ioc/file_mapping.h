#pragma once
#include <Windows.h>

namespace win32cpp
{
    inline namespace ioc
    {
        class IFileMapping
        {
        public:
            virtual auto CloseHandle(_In_ HANDLE hObject) -> BOOL = 0;
    
            virtual auto CreateFileMappingA(
                _In_ HANDLE hFile,
                _In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                _In_ DWORD flProtect,
                _In_ DWORD dwMaximumSizeHigh,
                _In_ DWORD dwMaximumSizeLow,
                _In_opt_ LPCSTR lpName
                ) -> HANDLE = 0;
    
            virtual auto CreateFileMappingW(
                _In_ HANDLE hFile,
                _In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                _In_ DWORD flProtect,
                _In_ DWORD dwMaximumSizeHigh,
                _In_ DWORD dwMaximumSizeLow,
                _In_opt_ LPCWSTR lpName
                ) -> HANDLE = 0;
    
            virtual auto MapViewOfFile(
                _In_ HANDLE hFileMappingObject,
                _In_ DWORD dwDesiredAccess,
                _In_ DWORD dwFileOffsetHigh,
                _In_ DWORD dwFileOffsetLow,
                _In_ SIZE_T dwNumberOfBytesToMap
                ) -> LPVOID = 0;
    
            virtual auto UnmapViewOfFile(_In_ LPCVOID lpBaseAddress) -> BOOL = 0;
        };
    
        class FileMappingImpl : public IFileMapping
        {
        public:
            auto CloseHandle(_In_ HANDLE hObject) -> BOOL override;
    
            auto CreateFileMappingA(
                _In_ HANDLE hFile,
                _In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                _In_ DWORD flProtect,
                _In_ DWORD dwMaximumSizeHigh,
                _In_ DWORD dwMaximumSizeLow,
                _In_opt_ LPCSTR lpName
                ) -> HANDLE override;
    
            auto CreateFileMappingW(
                _In_ HANDLE hFile,
                _In_opt_ LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                _In_ DWORD flProtect,
                _In_ DWORD dwMaximumSizeHigh,
                _In_ DWORD dwMaximumSizeLow,
                _In_opt_ LPCWSTR lpName
                ) -> HANDLE override;
    
            auto MapViewOfFile(
                _In_ HANDLE hFileMappingObject,
                _In_ DWORD dwDesiredAccess,
                _In_ DWORD dwFileOffsetHigh,
                _In_ DWORD dwFileOffsetLow,
                _In_ SIZE_T dwNumberOfBytesToMap
                ) -> LPVOID override;
    
            auto UnmapViewOfFile(_In_ LPCVOID lpBaseAddress) -> BOOL override;
        };
    }
}
