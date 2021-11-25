MEMORY {
  sram (rwx) : ORIGIN = 0x1000, LENGTH = 0x1FFF
  maskrom_mem (rx) : ORIGIN = 0x0000, LENGTH = 0x0FFF
}

SECTIONS
{

.init :
{
 KEEP (*(SORT_NONE(.init)))
}>maskrom_mem

.text :
{
  _stext = .;
  *(.text)
  _etext = .;

}>maskrom_mem

.data :
{
  _sdata = .;
  __global_pointer$ = _sdata + 0x000;
  *(.data)
  _edata = .;

}>sram

.bss :
{
  _sbss = .;
  *(.bss)
  _ebss = .;

}>sram

  }
