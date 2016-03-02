#define PUSH2_BULK_EP_OUT 0x01
#define TRANSFER_TIMEOUT  1000 // milliseconds

unsigned char frame_header[16] = {
  0xff, 0xcc, 0xaa, 0x88,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

libusb_transfer* frame_header_transfer;

if ((frame_header_transfer = libusb_alloc_transfer(0)) == NULL)
{
  printf("error: could not allocate frame header transfer handle\n");
}
else
{
  libusb_fill_bulk_transfer(
    frame_header_transfer,
    device_handle,
    PUSH2_BULK_EP_OUT,
    frame_header,
    sizeof(frame_header),
    on_frame_header_transfer_finished,
    NULL,
    TRANSFER_TIMEOUT);
}

libusb_transfer* pixel_data_transfer;

if ((pixel_data_transfer = libusb_alloc_transfer(0)) == NULL)
{
  printf("error: could not allocate transfer handle\n");
}
else
{
  libusb_fill_bulk_transfer(
    pixel_data_transfer,
    device_handle,
    PUSH2_BULK_EP_OUT,
    buffer,
    BUFFER_SIZE,
    on_buffer_transfer_finished,
    NULL,
    TRANSFER_TIMEOUT);
}
