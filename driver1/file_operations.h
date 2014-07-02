
struct file_operations fops=
{
	 open:scull_open,
	 write:scull_write,
	 read:scull_read,
	 release:scull_release
};
