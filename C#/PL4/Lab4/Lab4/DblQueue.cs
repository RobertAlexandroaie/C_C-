using System;
using System.Collections;
using System.Collections.Generic;

[Serializable]
public class DblQueue<T> : ICollection<T>, ICloneable
{
    // coada dubla este simulata prin List<T>
    protected List<T> internalList = null;
    
    public DblQueue()
    {
        this.internalList = new List<T>();
    }

    public DblQueue(ICollection<T> coll)
    {
        this.internalList = (List<T>)coll;
    }

    // numar elemente din coada (tip Read)
    public virtual int Count
    {
        get { return this.internalList.Count; }
    }
    
    public virtual bool IsSynchronized
    {
        get { return (false); }
    }
    
    public virtual object SyncRoot
    {
        get { return (this); }
    }

    // golirea cozii
    public virtual void Clear()
    {
        this.internalList.Clear();
    }

    // Crearea unei noi cozi duble
    public object Clone()
    {
        DblQueue<T> obiect = new DblQueue<T>();
        obiect.internalList = this.internalList;
        return obiect;
    }

    // Coada contine obj?
    public virtual bool Contains(T obj)
    {
        if (this.internalList.Contains(obj))
            return true;
        return false;
    }

    // copiere coada in Array incepand cu index
    public virtual void CopyTo(Array array, int index)
    {
        ArrayList a = new ArrayList(this.internalList.ToArray());

        for (int i = index; i < a.Count; i++)
        {
            array.SetValue(a[i],i-index);
        }
    }

    // scoaterea unui obiect din coada folosind LIFO
    public virtual T DequeueHead()
    {
        if (this.internalList.Count == 0)
            throw new InvalidOperationException("List is Empty!");

        T element = this.internalList.ToArray()[0];
        this.internalList.RemoveAt(0);
        return element; 
    }
    
    // scoaterea unui obiect din coada folosind FIFO
    public virtual T DequeueTail()
    {
        if (this.internalList.Count == 0)
            throw new InvalidOperationException("List is Empty!");

        T element = this.internalList.ToArray()[this.internalList.Count-1];
        this.internalList.RemoveAt(this.internalList.Count-1);
        return element; 
    }
    
    // Introducerea unui obiect in coada la inceputul cozii
    public virtual void EnqueueHead(T obj)
    {
        this.internalList.Insert(0, obj);
    }
    
    // Introducerea unui obiect in coada la sfarsitul cozii
    public virtual void EnqueueTail(T obj)
    {
        this.internalList.Insert(this.internalList.Count, obj);
    }
    
    // verificarea primului element din coada (metoda Peek)
    public virtual T PeekHead()
    {
        if (this.internalList.Count == 0)
            throw new InvalidOperationException("List is Empty!");
            
        T element = this.internalList.ToArray()[0];
        return element;
    }
    
    // verificarea ultimului element din coada (metoda Peek)
    public virtual T PeekTail()
    {
        if (this.internalList.Count == 0)
            throw new InvalidOperationException("List is Empty!");

        T element = this.internalList.ToArray()[this.internalList.Count-1];
        return element;
    }
    
    // enumerator
    public virtual IEnumerator GetEnumerator()
    {
        return this.internalList.GetEnumerator();
    }
    
    // coada transformata intr-un array
    public virtual T[] ToArray()
    {
        T[] elemente = new T[this.internalList.Count];
        elemente = this.internalList.ToArray();
        return elemente;
    }
    
    // eliminare spatiu in exces din coada
    public virtual void TrimExcess()
    {
        this.internalList.TrimExcess();
    }
    
    void System.Collections.Generic.ICollection<T>.Add(T item)
    {
        throw (new NotSupportedException("Use the EnqueueHead or EnqueueTail methods."));
    }
    
    // Copiere in array a cozii incepand cu index
    void System.Collections.Generic.ICollection<T>.CopyTo(T[] item, int index)
    {
        this.internalList.CopyTo(item, index);
    }
    
    bool System.Collections.Generic.ICollection<T>.Remove(T item)
    {
        throw (new NotSupportedException("Use the DequeueHead or DequeueTail methods."));
    }
    
    bool System.Collections.Generic.ICollection<T>.IsReadOnly
    {
        get { throw (new NotSupportedException("Not Supported.")); }
    }
    
    // enumerator
    IEnumerator<T>System.Collections.Generic.IEnumerable<T>.GetEnumerator()
    {
        return this.internalList.GetEnumerator();
    }
}