#include "logger.h"

namespace gxy {
	
void initLogger(const char * const argv)
{
  // FLAGS_log_dir=".";
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging(argv);
}

} // namespace gxy
