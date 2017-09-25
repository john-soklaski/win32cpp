#include "..\targetver.h"
#include <debug.hpp>
#include <error.hpp>
#include <module_info.hpp>
#include <string_extensions.hpp>
#include <service.hpp>

using namespace std;
using namespace win32cpp;

class testsvc : public service_base
{
public:
	testsvc() : service_base(L"TestSvc")
	{
	}

	void onContinue() override
	{
		TRACE(L"onContinue\n");
	}

	void onInitialize() override
	{
		TRACE(L"onInitialize\n");
	}

	void onPause() override
	{
		TRACE(L"onPause\n");
	}

	void onStop() override
	{
		TRACE(L"onStop\n");
	}
};

void wmain(int argc, const wchar_t* argv[])
{
	service_registration serviceRegistration;
	serviceRegistration.add(service_controller<testsvc>{});

	serviceRegistration.startDispatcher();
}