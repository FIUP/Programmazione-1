
//variante di f0 by: Simone M.

innesto* fine(innesto* in)
{
	if(!in->next)
	{
		return in;
	}
	else
	{
		innesto* inn=fine(in->next);
		return inn;
	}
}


innesto* f0(nodo*R)
{
	if(!R)
	{
		return 0;
	}
	else
	{
		innesto* in=f0(R->left);
		innesto* inn=f0(R->right);
		if(!in && !inn)
		{
			return new innesto(true, true, R, 0);
		}
		else if(in && !inn)
		{
			in->next=new innesto(false, true, R, 0);
			return in;
		}
		else
		{
			innesto* temp=fine(in);
			temp->next=inn;
			return in;
		}
	}
}
