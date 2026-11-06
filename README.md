# GSpad-DS4modle-auto-reconnect
PS5 13.6 专用 ELF 手柄插件
适配：盖世小鸡启明星二代 VID=0x0e6f PID=0x0184

## 功能清单
- 只识别 0x0e6f:0x0184，忽略其他所有HID设备
- DS4虚拟手柄上报，250Hz采样
- 自动重连：手柄关机/拔适配器自动销毁虚拟手柄，上电自动重建
- 首次接入弹窗账号绑定，绑定后重连不再弹窗
- 常驻ELF，加载一次即可，不需要网页
- 砍掉Xbox/Switch解析、网页面板、配置保存等冗余代码

## 加载方式
PLM Manager / autoload.txt
推荐加载时序：kstuff → SMP → 本ELF

## 重要提示
1. hid_parser.c 中的HID报文偏移是占位，**必须真机抓包，根据小鸡手柄真实HID报告修正偏移**，否则按键、陀螺仪错乱
2. 依赖社区标准 ps5sdk
3. 仅离线破解环境使用
