#define BLEMM_IMPL
#define BLEMM_LOG_LVL 5
#include "blemm.h"

#define DEFAULT_BUILD_DIR "./build/"
#define DEFAULT_SRC_DIR "./src/"
#define BINARY_NAME "program"

void mkdir_build()
{
	CMD(mkdir);
	CMD_APPEND(mkdir, "mkdir");
	CMD_APPEND(mkdir, DEFAULT_BUILD_DIR);
	CMD_EXEC_SYNC(mkdir);
	CMD_FREE(mkdir);
}

void build_simple_static_interface()
{
	mkdir_build();

	CMD(build);
	CMD_APPEND(build, "clang++");
	CMD_APPEND(build, DEFAULT_SRC_DIR"simple_static_interface.cpp");
	CMD_APPEND(build, "-o");
	CMD_APPEND(build, DEFAULT_BUILD_DIR"simple_static_interface");
	CMD_APPEND(build, "-std=c++20");
	CMD_APPEND(build, "-ggdb");
	CMD_EXEC_SYNC(build);
	CMD_FREE(build);
}

void build_table_paradigm()
{
	mkdir_build();

	CMD(build);
	CMD_APPEND(build, "clang++");
	CMD_APPEND(build, DEFAULT_SRC_DIR"table_paradigm.cpp");
	CMD_APPEND(build, "-o");
	CMD_APPEND(build, DEFAULT_BUILD_DIR"table_paradigm");
	CMD_APPEND(build, "-std=c++20");
	CMD_APPEND(build, "-ggdb");
	CMD_EXEC_SYNC(build);
	CMD_FREE(build);
}

void build_crtp()
{
	mkdir_build();

	CMD(build);
	CMD_APPEND(build, "clang++");
	CMD_APPEND(build, DEFAULT_SRC_DIR"crtp.cpp");
	CMD_APPEND(build, "-o");
	CMD_APPEND(build, DEFAULT_BUILD_DIR"crtp");
	CMD_APPEND(build, "-std=c++20");
	CMD_APPEND(build, "-ggdb");
	CMD_EXEC_SYNC(build);
	CMD_FREE(build);
}

void build_crtpOO()
{
	mkdir_build();

	CMD(build);
	CMD_APPEND(build, "clang++");
	CMD_APPEND(build, DEFAULT_SRC_DIR"crtpOO.cpp");
	CMD_APPEND(build, "-o");
	CMD_APPEND(build, DEFAULT_BUILD_DIR"crtpOO");
	CMD_APPEND(build, "-std=c++20");
	CMD_APPEND(build, "-ggdb");
	CMD_EXEC_SYNC(build);
	CMD_FREE(build);
}

void run()
{
	CMD(run);
	CMD_APPEND(run, DEFAULT_BUILD_DIR"crtp");
	CMD_EXEC_SYNC(run);
	CMD_FREE(run);

	CMD(run0);
	CMD_APPEND(run0, DEFAULT_BUILD_DIR"crtpOO");
	CMD_EXEC_SYNC(run0);
	CMD_FREE(run0);

	CMD(run1);
	CMD_APPEND(run1, DEFAULT_BUILD_DIR"simple_static_interface");
	CMD_EXEC_SYNC(run1);
	CMD_FREE(run1);

	CMD(run2);
	CMD_APPEND(run2, DEFAULT_BUILD_DIR"table_paradigm");
	CMD_EXEC_SYNC(run2);
	CMD_FREE(run2);
}

void print_usage()
{
	BLEMM_LOGI("Usage: ./blemm [arg]\n   * -> builds\n   run -> builds and runs");
}

int main(int argc, char** argv)
{
	BLEMM_REBUILD_ME(argc, argv);
	BLEMM_LOGI("--- BEGIN BLEMM BUILD SCRIPT ---");

	if (argc < 2)
	{
		print_usage();
		return 0;		
	}

	build_simple_static_interface();
	build_table_paradigm();
	build_crtp();
	build_crtpOO();

	SKIP_ARG();
	const bool should_run = strcmp(blemm_shift_args(&argc,&argv), "run") == 0;
	if (should_run)
	{
		run();
	}
	BLEMM_LOGI("--- END BLEMM BUILD SCRIPT ---");
}

