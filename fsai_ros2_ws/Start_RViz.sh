#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

profile_arg="${1:-carmaker}"

case "${profile_arg}" in
  carmaker)
    config_path="${script_dir}/src/rviz_config/carmaker_perception.rviz"
    ;;
  sensors)
    config_path="${script_dir}/src/rviz_config/sensors.rviz"
    ;;
  *)
    config_path="${profile_arg}"
    ;;
esac

if [[ ! -f "${config_path}" ]]; then
  echo "RViz config not found: ${config_path}" >&2
  echo "Usage: ./Start_RViz.sh [carmaker|sensors|/absolute/path/to/file.rviz]" >&2
  exit 1
fi

if ! command -v rviz2 >/dev/null 2>&1; then
  echo "rviz2 is not on PATH." >&2
  echo "Source ROS 2 and your workspace first, then rerun this launcher." >&2
  exit 1
fi

exec rviz2 -d "${config_path}"
