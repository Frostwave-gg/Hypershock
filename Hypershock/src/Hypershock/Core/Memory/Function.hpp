//====================================================================================================
/**
 *  Copyright (c) 2022 Frostwave.gg
 *
 *  This software is provided 'as-is', without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from the use of this software.
 *
 *  Permission is granted, free of charge, to anyone to use this software for non-commercial non-military purposes, and to alter it and redistribute it freely,
 *  subject to the following restrictions:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. The acknowledgement of the use of this software must be present and clearly visible in the product documentation and the product itself.
 *      3. This notice must not be removed from any source distribution.
 *
 *  Permission is denied for any military purpose without explicit cooperation agreement between the third party and Frostwave.gg.
 *  For military use, contact Frostwave.gg.
 *  (Heads up, Frostwave.gg does not support military use of its software, therefore rates may be astronomical)
 *
 *  Permission is denied to anyone to use this software, alter it or redistribute it for commercial, or commercial-related purposes,
 *  without permission of Frostwave.gg or its subsidiaries. This includes any and all products and activity with potential monetary gain,
 *  including but not limited to commercial or advertisement products, products containing advertisement, training software and in-house simulation software.
 *  Requirements for commercial use are following:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. Frostwave.gg is eligible for 7.5% of the first 100,000 USD of the products profit, and 15% of all profit after.
 *      3. This notice must not be removed from any source distribution.
 *      4. A formal business agreement from Frostwave.gg or its subsidiaries must be acquired for any commercial use.
 *      5. The acknowledgement of the use of this software must be present and clearly visible in the product documentation.
 *
 *  Open-source commercial products may be eligible to a reduced owed profit percentage - contact Frostwave.gg for further information.
 *
 */
//====================================================================================================
#pragma once
#ifndef HYPERSHOCK_FUNCTION_HPP
#define HYPERSHOCK_FUNCTION_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    /**
     *
     * @tparam T
     */
    template<typename T>
    class HYPERSHOCK_PUBLIC_API FunctionExecutor {};
    //====================================================================================================
    /**
     *
     * @tparam Ret
     * @tparam Args
     */
    template<typename Ret, typename... Args>
    class HYPERSHOCK_PUBLIC_API FunctionExecutor<Ret(Args...)>
    {
    public:
        /**
         *
         * @param args
         * @return
         */
        FORCE_INLINE Ret operator()(Args ... args) noexcept
        {
            CHECK(m_Function)
            CHECK(m_Execute)
            return m_Execute(m_Function, args...);
        }
        /**
         *
         * @return
         */
        explicit FORCE_INLINE operator bool() const noexcept
        {
            return m_Function != nullptr && m_Execute != nullptr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE bool IsValid() const noexcept
        {
            return m_Function != nullptr && m_Execute != nullptr;
        }

    protected:
        //====================================================================================================
        /**
         *
         * @param function
         */
        FORCE_INLINE FunctionExecutor(void*& function) noexcept : m_Function(function)
        {
        }
        /**
         *
         */
        virtual FORCE_INLINE ~FunctionExecutor() noexcept = default;
        //====================================================================================================
        /**
         *
         * @tparam T
         * @param function
         */
        template<typename T>
        FORCE_INLINE void GenerateExecutor(const T& function) noexcept
        {
            m_Execute = [](void* func, Args... args) -> Ret
            {
                return ((T*)func)->operator()(args...);
            };
        }
        /**
         *
         * @param executor
         */
        FORCE_INLINE void ReceiveExecutor(const FunctionExecutor<Ret(Args...)>& executor) noexcept
        {
            m_Execute = executor.m_Execute;
        }

    private:
        void*& m_Function;
        Ret (*m_Execute)(void*, Args...);
    };
    //====================================================================================================
    /**
     *
     * @tparam Args
     */
    template<typename... Args>
    class HYPERSHOCK_PUBLIC_API FunctionExecutor<void(Args...)>
    {
    public:
        /**
         *
         * @param args
         */
        FORCE_INLINE void operator()(Args... args) noexcept
        {
            CHECK(m_Function)
            CHECK(m_Execute)
            m_Execute(m_Function, args...);
        }
        /**
         *
         * @return
         */
        explicit FORCE_INLINE operator bool() const noexcept
        {
            return m_Function != nullptr && m_Execute != nullptr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE bool IsValid() const noexcept
        {
            return m_Function != nullptr && m_Execute != nullptr;
        }

    protected:
        //====================================================================================================
        /**
         *
         * @param function
         */
        FORCE_INLINE FunctionExecutor(void*& function) noexcept : m_Function(function)
        {
        }
        /**
         *
         */
        virtual FORCE_INLINE ~FunctionExecutor() noexcept = default;
        //====================================================================================================
        /**
         *
         * @tparam T
         * @param function
         */
        template<typename T>
        FORCE_INLINE void GenerateExecutor(const T& function) noexcept
        {
            m_Execute = [](void* func, Args... args) -> void
            {
                return ((T*)func)->operator()(args...);
            };
        }
        /**
         *
         * @param executor
         */
        FORCE_INLINE void ReceiveExecutor(const FunctionExecutor<void(Args...)>& executor) noexcept
        {
            m_Execute = executor.m_Execute;
        }

    private:
        void*& m_Function;
        void (*m_Execute)(void*, Args...);
    };
    //====================================================================================================
    /**
     *
     * @tparam T
     */
    template<typename T> class HYPERSHOCK_PUBLIC_API Function {};
    //====================================================================================================
    /**
     *
     * @tparam Ret
     * @tparam Args
     */
    template<typename Ret, typename ...Args>
    class HYPERSHOCK_PUBLIC_API Function<Ret(Args...)> : public FunctionExecutor<Ret(Args...)>
    {
    public:
        //====================================================================================================
        /**
         *
         */
        FORCE_INLINE Function() noexcept : FunctionExecutor<Ret(Args...)>(m_Function),
                m_Function(nullptr), m_DeleteFunction(nullptr), m_CopyFunction(nullptr)
        {
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE Function(Function<Ret(Args...)>&& other) noexcept : FunctionExecutor<Ret(Args...)>(m_Function),
                m_Function(other.m_Function ? other.m_Function : nullptr),
                m_DeleteFunction(other.m_DeleteFunction ? other.m_DeleteFunction : nullptr),
                m_CopyFunction(other.m_CopyFunction ? other.m_CopyFunction : nullptr)
        {
            ReceiveExecutor(other);

            other.m_Function = nullptr;
            other.m_DeleteFunction = nullptr;
            other.m_CopyFunction = nullptr;
        }
        /**
         *
         * @tparam T
         * @param function
         */
        template<typename T>
        FORCE_INLINE Function(const T& function) noexcept : FunctionExecutor<Ret(Args...)>(m_Function),
                m_Function(nullptr), m_DeleteFunction(nullptr), m_CopyFunction(nullptr)
        {
            Copy(function);
            GenerateExecutor(function);
        }
        /**
         *
         */
        FORCE_INLINE Function(TYPE_OF_NULLPTR) noexcept : FunctionExecutor<Ret(Args...)>(m_Function),
                m_Function(nullptr), m_DeleteFunction(nullptr), m_CopyFunction(nullptr)
        {
        }
        /**
         *
         */
        virtual FORCE_INLINE ~Function() noexcept override
        {
            if (m_DeleteFunction)
            {
                m_DeleteFunction(m_Function);
            }
        }
        //====================================================================================================
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE Function& operator=(Function&& other) noexcept
        {
            if (m_Function != nullptr && m_DeleteFunction != nullptr)
            {
                m_DeleteFunction(m_Function);
            }

            m_Function = other.m_Function;
            m_DeleteFunction = other.m_DeleteFunction;
            m_CopyFunction = other.m_CopyFunction;

            ReceiveExecutor(other);

            other.m_Function = nullptr;
            other.m_DeleteFunction = nullptr;
            other.m_CopyFunction= nullptr;

            return *this;
        }
        /**
         *
         * @tparam T
         * @param function
         * @return
        */
        template<typename T>
        FORCE_INLINE Function& operator=(const T& function) noexcept
        {
            Copy(function);
            GenerateExecutor(function);

            return *this;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE Function& operator=(TYPE_OF_NULLPTR) noexcept
        {
            if (m_Function != nullptr && m_DeleteFunction != nullptr)
            {
                m_DeleteFunction(m_Function);
            }

            m_Function = nullptr;

            return *this;
        }

    private:
        /**
         *
         * @tparam T
         * @param function
         */
        template<typename T>
        FORCE_INLINE void Copy(const T& function) noexcept
        {
            if (m_Function != nullptr && m_DeleteFunction != nullptr)
            {
                m_DeleteFunction(m_Function);
            }
            else
            {
                delete (T*)m_Function;
            }

            if (m_CopyFunction != nullptr)
            {
                m_Function = m_CopyFunction(&function);
            }
            else
            {
                m_Function = new T(function);
            }

            m_DeleteFunction = [](void* func) -> void
            {
                delete (T*)func;
            };

            m_CopyFunction = [](void* func) -> void*
            {
                if (func == nullptr)
                {
                    return nullptr;
                }

                return new T(*(T*)func);
            };
        }

    private:
        void* m_Function;
        void (*m_DeleteFunction)(void*);
        void* (*m_CopyFunction)(void*);
    };
    //====================================================================================================
    // TODO: make function version for void(args)
}
//====================================================================================================
#endif //HYPERSHOCK_FUNCTION_HPP
//====================================================================================================